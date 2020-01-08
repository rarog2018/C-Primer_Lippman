#include <iostream>

using namespace std;

int main(void)
{
    double dval; int ival; int *pi;
    int p;
    // this assignment is illegal because we are assigning
    // the pointer (address) to an int
    // to correct this we can give a nonNull address
    // for the pointer and then assign 0 to the address (variable)
    // dval = ival = pi = 0;
    pi = &p;
    dval = ival = *pi = 0;
    cout << "dval: " << dval << ", ival: " << ival
        << ", pi: " << pi << endl;
    // or we can separately assign 0 for a pointer and other
    // 2 variables
    dval = ival = 0;
    pi = 0;
    cout << "dval: " << dval << ", ival: " << ival
        << ", pi: " << pi << endl;
}
