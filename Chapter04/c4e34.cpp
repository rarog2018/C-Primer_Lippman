#include <iostream>

using namespace std;

int main(void)
{
    char cval = 'z';
    int ival = 12;
    float fval = 0.89;
    double dval = 3.14;

    // first fval gets promoted to int
    // then the condition is checked
    // if fval is not 0 condition is true
    // if fval is 0 (even if as in this
    // case it is 0.89) then condition
    // is false
    if (fval)
        cout << "Fval is not 0 " << fval << endl;
    else
        cout << "Fval is 0 " << fval << endl;

    // first ival gets promoted to float
    // and addition happens
    // then the result of fval + ival
    // is promoted to double and
    // assigned to dval variable
    dval = fval + ival;
    cout << "fval: " << fval << " + ival: " << ival
        << " = " << dval << endl;

    // ival * cval is evaluated first
    // cval gets promoted from char to int
    // so its value is not 'z' but 122
    // the result of this expression
    // is converted to double and added
    // to dval, so result has type double
    auto result = dval + ival * cval;
    cout << "dval: " << dval << " + ival: " << ival
        << " * (int) cval: " << (int) cval << " = "
        << result << endl;
}
