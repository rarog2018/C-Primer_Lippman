#include <iostream>
#include "c06e08header.h"

using namespace std;
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
