#include <iostream>
using namespace std;
int main(void)
{
    int x, y, max, min;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "\nEach number in the range: " << endl;

    // assign values to min, max variables depending on the values of x, y
    if (x > y)
    {
        max = x;
        min = y;
    }
    else
    {
        max = y;
        min = x;
    }
    // print each value in the range
    while (min <= max)
    {
        cout << min++ << endl;
    }
    return 0;
}