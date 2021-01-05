#include <iostream>
#include <vector>
#include <string>
using namespace std;

// instantiation declaration, it promises that somewhere in the program there
// is an instantiation definition for it, the compiler won't generate the code
// for this instantiation in this file when it sees this line
extern template class vector<string>;

// instantiation definition, instantiates all the members of this template,
// the compiler will generate the code
template class vector<Sales_data>;

int main(void)
{
    return 0;
}