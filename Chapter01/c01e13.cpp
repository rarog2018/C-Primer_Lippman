#include <iostream>
using namespace std;
int main(void)
{
    int sum = 0;
    /////////////////       e09         /////////////////////////////////////
    for (int val = 50; val <= 100; ++val)
    {
        sum += val;
    }
    cout << "The sum of the numbers 50 to 100 is " << sum << endl;

    /////////////////       e10         /////////////////////////////////////
    for (int val = 10; val >= 0; --val)
    {
        cout << val << endl;
    }

    /////////////////       e11         /////////////////////////////////////
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "\nEach number in the range: " << endl;
    for (int temp = x; temp <= y; ++temp)
    {
        cout << temp << endl;
    }
    return 0;
}