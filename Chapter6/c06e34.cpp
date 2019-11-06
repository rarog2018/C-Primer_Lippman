#include <iostream>

using namespace std;
int factorial(int val)
{
    if (val != 0)
        return factorial(val - 1) * val;
    return 1;
}
int main(void)
{
    // for positive arguments the function works as before
    cout << factorial(6) << endl;
    // but if we pass a negative value as an argument the function will loop
    // infinitely (program will crash), because the value will always be different
    // than 0
    cout << factorial(-1) << endl;
    return 0;
}