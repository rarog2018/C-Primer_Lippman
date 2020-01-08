#include <iostream>

using namespace std;
// we are passing 'val - 1' instead of val--, because postdecrement operator's
// value is the value before decrementation, so in this case we would send
// to a factorial function always the same value

int factorial(int val) // val is 6
{
    cout << val << endl;
    if (val > 1)
        return factorial(val--) * val; // create a temporary copy of an object
    // val with value 6 and then decrement the 'val' object so it has value 5
    // the problem is that 'val' is a local variable, so each time factorial
    // is called - new 'val' object with a value 6 is created
    return 1;
}

int main(void)
{
    int n = 6;
    // as we can see the value of the 'val' variable is always 6
    cout << factorial(6) << endl;
    return 0;
}