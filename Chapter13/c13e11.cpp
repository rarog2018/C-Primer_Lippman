#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    // copy constructor declaration
    HasPtr(const HasPtr &o);
    // assignment operator declaration
    HasPtr &operator=(const HasPtr &);
    // destructor
    ~HasPtr();

    void print() const;

private:
    std::string *ps;
    int i;
};

// destructor definiton
HasPtr::~HasPtr()
{
    cout << "Using destructor" << endl;
    delete ps;
}

// assignment operator definition
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    cout << "Using assignment operator" << endl;
    delete ps; // delete old string
    ps = new string(*rhs.ps);
    i = rhs.i;
    return *this;
}

// copy constructor definition
HasPtr::HasPtr(const HasPtr &o) : ps(new string(*o.ps)), i(o.i) {}

// print the addresses
void HasPtr::print() const
{
    cout << &this->ps << " " << this->ps << " " << *this->ps << endl;
}
int main(void)
{
    HasPtr abc("Witcher");
    HasPtr cde("LOTR");
    cde.print();
    cde = abc;

    abc.print();
    cde.print();
    return 0;
}