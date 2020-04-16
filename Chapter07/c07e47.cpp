#include <iostream>
using namespace std;

// The constructor that takes a single string should be explicit. Otherwise
// calling members that take Sales_data object as argument will create a
// temporary Sales_data object constructed implicitly by the very constructor
// that we are discussing.
// In some cases it makes sense, but there are members like combine() that it
// is just wasteful to create the temporary Sales_data object and discard it
// moments later.
// I do not see drawbacks, because it gives the control of what is converted
// and what is not, so when conversion happen we know that it was intended to
// happen.

int main(void)
{
    return 0;
}