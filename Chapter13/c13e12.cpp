#include <iostream>
using namespace std;

/*bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}*/

// destructor on accum
// destructor on item1
// destructor on item2
// each of the above destructor calls also call appropriate destructors for
// Sales_data string members

int main(void)
{
    return 0;
}