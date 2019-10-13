#include <iostream>

using namespace std;
int factorial(int n);
int main(void)
{
    cout << factorial(7) << endl;
    return 0;
}

int factorial(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // recursive case
    return n * factorial(n - 1);
}