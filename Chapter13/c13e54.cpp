#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// without changing the copy-swap assignment operator, the code won't compile
// because the functions are ambiguous

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const string &s, int n) : ps(new string(s)), i(n) {}
    // copy constructor declaration
    HasPtr(const HasPtr &o);
    // assignment operator declaration
    HasPtr &operator=(const HasPtr &);
    // ADDED: '<' operator
    bool operator<(const HasPtr &) const;
    // destructor
    ~HasPtr();
    // added move constructor
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }

    // the main difference between this move-assignment operator and copy-swap
    // assignment is the self-assignment test that move-assignment does
    // if the test passes, function does no operations (there is no point to
    // copy or move object to temp object, then destroy the objec, then copy from the
    // temp to the object, exactly the same data that we just destroyed from
    // this object)
    HasPtr &operator=(HasPtr &&rhs) noexcept;
    // // assignment operator is both the move- and copy-assignment operator
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }

    void print() const;

private:
    string *ps;
    int i;
};

int main(void)
{
    HasPtr hp2("Witcher", 1);
    HasPtr hp;

    hp = hp2;
    cout << "hp addresses after regular assignment: " << endl;
    hp.print();
    cout << "hp2 addresses:" << endl;
    hp2.print();

    hp = std::move(hp2);
    cout << "hp addresses after std::move(hp2): " << endl;
    hp.print();
    cout << "hp2 addresses after std::move(hp2): " << endl;
    hp2.print();

    return 0;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    cout << "Using move assignment" << endl;
    // self-assignment test
    if (this != &rhs)
    {
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}

// swap definition
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    // cout << "Using swap()" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

// destructor definiton
HasPtr::~HasPtr()
{
    // cout << "Using destructor" << endl;
    delete ps;
}

// ADDED
// '<' operator definition
bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *this->ps < *rhs.ps;
    // return *ps < *rhs.ps;
}
// CORRECTED
// assignment operator definition
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    // cout << "Using assignment operator" << endl;
    auto newp = new string(*rhs.ps); // copy the right-hand string
    delete ps;                       // delete old string, free the memory
    ps = new string(*rhs.ps);        // copy data from rhs to 'this' object
    i = rhs.i;
    return *this; // return this object
}

// copy constructor definition
HasPtr::HasPtr(const HasPtr &o) : ps(new string(*o.ps)), i(o.i)
{
    // cout << "Using copy constructor" << endl;
}

// print the addresses
void HasPtr::print() const
{
    cout << &(*ps) << " " << &ps << " " << &i << endl;
}