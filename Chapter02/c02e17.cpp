#include <iostream>

int main(void)
{
    int i, &ri = i;
    i = 5;
    ri = 10;

    // prints "10 10", because ri is a reference to 'i', so when we assign 10
    // to it, it is assigned to 'i' as well, because it is assigned to the same
    // place in memory
    std::cout << i << " " << ri << std::endl;
    std::cout << "address of i = " << &i << " address of ri = " << &ri << std::endl;
    return 0;
}