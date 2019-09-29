#include <iostream>
int main()
{
    int sum = 0, val = 1;
    /* while (val <= 10) {
    sum += val; // assigns sum + val to sum
    ++val; // add 1 to val
    }*/

    // same loop without a block, it looks cryptic, reminds me of lambdas
    while (val <= 10 && (sum += val, ++val))
        ;

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}