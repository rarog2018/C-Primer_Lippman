#include <iostream>

using namespace std;
// I would put both of them in a header file. First one is a definition
// of an inline function, which can be defined multiple times in a program
// but all of the definitions must match exactly.
inline bool eq(const BigInt &, const BigInt &) { ... }
void putValues(int *arr, int size);
int main(void)
{
    return 0;
}