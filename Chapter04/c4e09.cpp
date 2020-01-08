#include <iostream>

using namespace std;

int main(void)
{
    const char *cp = "Hello World";
    // We evaluate operands left to right. First we check if cp is
    // not a NULL pointer and then we check if the value of the
    // element is not zero
    // If we would assign an empty string to cp then left operand would
    // evaluate as true because it would point to a nonNULL place
    // in memory, but the right operand would be false
    if (cp && *cp)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << &cp << " " << cp << " " << *cp << endl;
}
