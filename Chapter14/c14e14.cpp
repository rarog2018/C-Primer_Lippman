#include <iostream>
using namespace std;

// it is more efficient to define operator+ using operator+=, because operato+=
// works in place, without creating a temporary object, so it would be wasteful
// to use operator+ that has to create a temp object  to define operator+=

int main(void)
{
    return 0;
}