#include <iostream>

using namespace std;

int main()
{
    // the result will be 105
    float a = 5 + 10 * 20/2;
    cout << "The value of a is: " << a << endl;
    // with parenthesis
    float b = 5 + ((10 * 20) / 2);
    cout << "The value of b is: " << b << endl;
    return 0;
}
