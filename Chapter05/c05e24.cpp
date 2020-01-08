#include <iostream>
#include <stdexcept>

using namespace std;
int main(void)
{
    int a, b;
    cout << "Type two integers: ";
    cin >> a >> b;
    if (b == 0)
    {
        throw runtime_error("You can't divide by 0!\n");
    }
    cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}