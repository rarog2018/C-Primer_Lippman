#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // valid, but the value will be truncated to 1
    int ival = 1.01;
    cout << "ival = " << ival << endl;

    /////////////////////           b           //////////////////////////////
    // invalid: reference cannot be bound to an rvalue
    // int &rval1 = 1.01;

    /////////////////////           c           //////////////////////////////
    // valid, rval2 is bound to ival
    int &rval2 = ival;
    cout << "rval2 = " << rval2 << endl;

    /////////////////////           d           //////////////////////////////
    // invalid: reference has to be initialized
    // int &rval3;

    return 0;
}