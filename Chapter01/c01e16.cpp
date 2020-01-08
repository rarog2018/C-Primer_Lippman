#include <iostream>
using namespace std;
int main(void)
{
    cout << "Enter some integers: ";
    int sum = 0, val = 0;
    // while val is an int
    while (cin >> val)
    {
        sum += val; // add val to current value of sum
    }
    cout << "The sum is: " << sum << endl;
    return 0;
}