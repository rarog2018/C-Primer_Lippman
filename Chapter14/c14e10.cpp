#include <iostream>
#include "c14Sales_data.h"
using namespace std;

int main(void)
{
    Sales_data ob;
    cin >> ob;

    // a) 0-201-99999-9 10 24.95
    // this will work correctly, because the first value 0-201-99999-9 can be
    // interpreted as a string, so it will be correctly stored in the ob.bookNo
    // attribute, then after whitespace we have a number: 10, which is an integer
    // so it can be correctly stored in the ob.units_sold attribute, and lastly
    // we have 24.95 which can be interpreted as a double, so it will be correctly
    // stored in the price variable, which then will be used to compute the
    // ob.revenue attribute

    // b) 10 24.95 0-210-99999-9
    // this will not work as intended - 10 can be interpreted as a string and
    // it will be correctly stored in the member ob.bookNo, 24.95 is not an int
    // and because of that 24 will be stored in the int member ob.units_sold
    // and .95 will be interpeted as 0.95 and stored in variable price, which
    // is not what we intended
    // the isbn will be read but not processed, maybe we should add some sort
    // of a test if there is something waiting in the buffer to be processed

    cout << endl;
    cout << ob << endl;
    return 0;
}