#include <iostream>
using namespace std;

// The pointerlike version of HasPtr would not benefit from defining its own
// version of swap(), because the types are: string *, int, size_t *, so 2 pointers
// and an int which all are a built-in types, which are handled by a std::swap
// function correctly

int main(void)
{
    return 0;
}