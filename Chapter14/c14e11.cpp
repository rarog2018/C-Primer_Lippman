#include <iostream>
using namespace std;

// this version of the operator>> does not check for the possible IO errors,
// which might put the object in the invalid state
// the a) input will work correctly, the b) input will put the object in the
// invalid state

/*
istream &operator>>(istream &in, Sales_data &s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
*/

int main(void)
{
    return 0;
}