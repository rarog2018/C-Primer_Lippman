#include <iostream>
using namespace std;
int main(void)
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val++;
    }
    cout << "The sum of the numbers 50 to 100 is " << sum << endl;
    return 0;
}