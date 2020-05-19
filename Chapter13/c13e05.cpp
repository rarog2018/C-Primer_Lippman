#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    // copy constructor declaration
    HasPtr(const HasPtr &o);

    void print() const;

private:
    std::string *ps;
    int i;
};

// copy constructor definition
HasPtr::HasPtr(const HasPtr &o) : ps(new string(*o.ps)), i(o.i) {}

// print the addresses
void HasPtr::print() const
{
    cout << &this->ps << " " << this->ps << endl;
}
int main(void)
{
    HasPtr abc("Witcher");
    HasPtr cde(abc);

    abc.print();
    cde.print();
    return 0;
}