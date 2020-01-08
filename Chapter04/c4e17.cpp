#include <iostream>

using namespace std;

int main(void)
{
    int a = 1, b = 1;
    // Prefix form increments its operand and yields the changed
    // object as its result.
    // Postfix for increments its operand but yields the copy
    // of the original unchanged value
    a = ++b;    // first increment b, so it equals 2, and assign it to a
    cout << "a = " << a << " b = " << b << endl;
    a = b++;    // increment b and yield the copy of previous value
    // the value of b will be 3, but its previous value 2 will be
    // assigned to a
    cout << "a = " << a << " b = " << b << endl;
}
