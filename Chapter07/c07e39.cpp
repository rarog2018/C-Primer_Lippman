#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// It would be illegal for two constructors to have only one argument which
// would be a default argument, because we would have 2 constructors that could
// be used when the object is created without an argument.
// It would be ambiguous which one to use

// Constructor(string s = "") ...
// Constructor(ostream &is = cin)
int main(void)
{
    // Constructor object; // should it be initialized with an empty string or
    // use 'cin' to get the data from the user? Because of that it is illegal.
    return 0;
}