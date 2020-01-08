#include <iostream>

using namespace std;
unsigned long long factorial(unsigned n);
int main(void)
{
    unsigned long long n;
    do
    {
        cout << "Type a positive number: ";
        cin >> n;
        cout << "Factorial of number " << n << " is " << factorial(n) << endl;
        cout << endl;
    } while (n >= 0);

    return 0;
}

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