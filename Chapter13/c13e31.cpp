#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
    cout << *this->ps << " " << this->i << endl;
}
int main(void)
{
    vector<string> sVec{"LOTR", "Witcher", "Malazan", "WOT", "Stormlight"};
    vector<HasPtr> hpVec;

    for (int i = 0; i < sVec.size(); ++i)
    {
        hpVec.push_back(HasPtr(sVec[i], i));
    }

    cout << "Before sorting: " << endl;
    for (auto e : hpVec)
    {
        e.print();
    }

    sort(hpVec.begin(), hpVec.end());

    cout << "\n\nAfter sorting: " << endl;
    for (auto e : hpVec)
    {
        e.print();
    }
    return 0;
}