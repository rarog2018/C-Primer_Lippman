#include <iostream>
using namespace std;
int main(void)
{
    int sum = 0; // define and initialize sum to 0
    // define and initialize i to -100
    // check if i is less or equal to 100 on each step
    // increment i (prefix incrementation)
    // in the loop add the value of i to current value of sum
    for (int i = -100; i <= 100; ++i)
        sum += i;

    // the final value of sum should be 0
    cout << sum << endl;
    return 0;
}