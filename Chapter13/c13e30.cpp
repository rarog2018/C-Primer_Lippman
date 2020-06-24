#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    // copy constructor declaration
    HasPtr(const HasPtr &o);
    // assignment operator declaration
    HasPtr &operator=(const HasPtr &);
    // destructor
    ~HasPtr();

    void print() const;

private:
    string *ps;
    int i;
};

// swap definition
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "Using swap()" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

// destructor definiton
HasPtr::~HasPtr()
{
    cout << "Using destructor" << endl;
    delete ps;
}

// CORRECTED
// assignment operator definition
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    cout << "Using assignment operator" << endl;
    auto newp = new string(*rhs.ps); // copy the right-hand string
    delete ps;                       // delete old string, free the memory
    ps = new string(*rhs.ps);        // copy data from rhs to 'this' object
    i = rhs.i;
    return *this; // return this object
}

// copy constructor definition
HasPtr::HasPtr(const HasPtr &o) : ps(new string(*o.ps)), i(o.i)
{
    cout << "Using copy constructor" << endl;
}

// print the addresses
void HasPtr::print() const
{
    cout << &this->ps << " " << this->ps << " " << *this->ps << endl;
}
int main(void)
{
    HasPtr abc("Witcher");
    HasPtr cde("LOTR");
    HasPtr efg(cde);
    cde.print();
    swap(cde, abc);

    abc.print();
    cde.print();
    efg.print();
    return 0;
}