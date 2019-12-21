#include <iostream>

#define BigInt long // to prevent error message
using namespace std;
// I would put both of them in a header file. First one is a definition
// of an inline function, which can be defined multiple times in a program
// but all of the definitions must match exactly. Also the first one, because
// it is a definition is a good candidate to put in a source file. It can be
// put in the header file with its definition as well (because it's inline).
inline bool eq(const BigInt &, const BigInt &)
{ /*...*/
    return true;    // to prevent warning message
};
// The second one is a very good candidate to put in a header file because it
// is a declaration of a regular function. The definition of this function
// should be put in to a source file.
void putValues(int *arr, int size);
int main(void)
{
    return 0;
}