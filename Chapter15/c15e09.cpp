#include <iostream>
using namespace std;

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

    // static type is BaseCN &, but dynamic type is DerivedCN
    BaseCN &ref = item;
    return 0;
}