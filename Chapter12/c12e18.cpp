#include <iostream>
using namespace std;

// shared_ptr does not need a release(), because there can be multiple shared_ptrs
// that point to the same memory, while unique_ptr has to 'release' itself
// first, before other pointer can point to that memory

int main(void)
{
    return 0;
}