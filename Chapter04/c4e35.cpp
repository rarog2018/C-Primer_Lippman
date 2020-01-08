#include <iostream>

using namespace std;

int main(void)
{
    char cval = 'a'; int ival = 1; unsigned int ui = 2;
    float fval = 1.01; double dval = 1.01;

    // first 'a' is promoted to int
    // addition happens
    // then the result is explicitly
    // converted to char and assigned
    // to cval
    cval = 'a' + 3;
    cout << cval << " before conversion: " << ('a' + 3) << endl;

    // ival gets promoted to double
    // the result is converted to unsigned int
    // substraction happens
    // the result is converted to float and
    // assigned to fval
    fval = ui - ival * 1.0;
    cout << fval << " before conversion: "
        << (ui - ival * 1.0) << endl;

    // ui gets converted to float
    // the result is converted to double end
    // assigned to dval
    fval = -2.01;
    dval = ui * fval;
    cout << dval << " before conversion: " << (ui * fval) << endl;

    // ival, fval are promoted to double
    // the result of the addition is
    // converted to int and then to char
    cval = ival + fval + dval;
    cout << cval << " before conversion: " << (ival + fval + dval) << endl;
}
