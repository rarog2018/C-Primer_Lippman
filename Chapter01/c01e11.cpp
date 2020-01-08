#include <iostream>
using namespace std;
int main(void)
{
    int x, y, temp;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << "\nEach number in the range: " << endl;
    temp = x;
    while (temp <= y)
    {
        cout << temp++ << endl;
    }
    return 0;
}