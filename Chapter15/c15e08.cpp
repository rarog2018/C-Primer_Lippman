#include <iostream>
using namespace std;

// static type is a type with which a variable is defined or that an expression
// yields

// dynamic type is a type of an object at run time, it may differ from the static
// type. A pointer or reference to a base-class type can refer to an object
// of deriverd type

class BaseCN
{ /* ... */
};
class DerivedCN : public BaseCN
{ /* ... */
};

int main(void)
{
    DerivedCN item;
    // here the static type of 'p' is BaseCN *, but its dynamic type is actually
    // DerivedCN, because it points to and DerivedCN object
    BaseCN *p = &item;

    auto n = 15 + 3; // here the static type of this expression is int
    return 0;
}