#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    // now the constructor initializes the new counter member
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), counter(new size_t(1)) {}
    // copy constructor, now copies also the counter and increments it
    HasPtr(const HasPtr &o);
    // assignment operator declaration
    HasPtr &operator=(const HasPtr &);
    // destructor
    ~HasPtr();

    void print() const;

private:
    string *ps;
    int i;
    size_t *counter; // new member that points to dynamically allocated memory,
                     // that stores the counter of how many objects share the state
};

// destructor definiton, now checks if the counter goes to zero, if so deletes
// the members
HasPtr::~HasPtr()
{
    cout << "Using destructor" << endl;
    if (--*counter == 0)
    {
        delete ps;      // delete string
        delete counter; // delete the counter
    }
}

// CORRECTED, now checks if the counter goes to 0
// assignment operator definition
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    cout << "Using assignment operator" << endl;
    ++*rhs.counter;          // increment the rhs's counter
    if (--*rhs.counter == 0) // if the counter is 0
    {
        delete ps;      // delete old string, free the memory
        delete counter; // and the counter
    }
    ps = rhs.ps; // copy data from rhs to 'this' object
    i = rhs.i;
    counter = rhs.counter;
    return *this; // return this object
}

// copy constructor definition
HasPtr::HasPtr(const HasPtr &o) : ps(o.ps), i(o.i), counter(o.counter)
{
    cout << "Using copy constructor" << endl;
    ++*counter; // increment the value of the counter
}

// print the addresses
void HasPtr::print() const
{
    cout << &this->ps << " " << this->ps << " " << *this->ps << " "
         << this->counter << " " << *this->counter << endl;
}
int main(void)
{
    HasPtr abc("Witcher");
    HasPtr cde("LOTR");
    HasPtr efg(cde);
    cde.print();
    cde = abc;

    abc.print();
    cde.print();
    efg.print();
    return 0;
}