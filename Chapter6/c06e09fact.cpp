#include "c06e08header.h"

unsigned long long factorial(unsigned n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // recursive case
    return n * factorial(n - 1);
}