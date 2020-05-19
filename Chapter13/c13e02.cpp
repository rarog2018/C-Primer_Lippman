#include <iostream>
using namespace std;

// Sales_data::Sales_data(Sales_data rhs);
// The declaration is illegal because the parameter is not a reference
// The copy constructor is used to initialize nonreference parameters, therefore
// when passing the argument the copy constructor would be called to copy that
// argument, but because the argument is again a copy, the copy constructor is
// called again and again and so on infinitely.

int main(void)
{
    return 0;
}