#include <iostream>

int main(void)
{
    // it is legal
    int i = 100, sum = 0;         // main scope 'i'
    for (int i = 0; i != 10; ++i) // for loop local scope 'i'
        sum += i;                 // values 0 - 9 are added to sum, because we add local 'i'

    // prints 100 45, because for loop 'i' is already destroyed object, so it
    // prints the main scope 'i' that has a value 100, and sum that after
    // addition has a value 45
    std::cout << i << " " << sum << std::endl;
    return 0;
}