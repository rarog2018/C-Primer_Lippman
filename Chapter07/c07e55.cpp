#include <iostream>
using namespace std;

// It is not a literal class.
// It is and aggregate class, but it has a member of type string, which is
// not a literal type.
struct Data
{
    int ival; // literal, arithmetic type
    string s; // non literal type
};

int main(void)
{
    return 0;
}