#include <iostream>
#include <stdexcept>

using namespace std;
int main(void)
{
    bool repeat = true;
    while (repeat)
    {
        int a, b;
        cin.clear();
        fflush(stdin);
        cout << "Type two integers: ";
        repeat = false;
        try
        {
            cin >> a >> b;
            if (b == 0)
            {
                throw runtime_error("You can't divide by 0!");
            }
        }
        catch (runtime_error err)
        {
            cout << err.what() << " Try again:" << endl;
            repeat = true;
            continue;
        }
        cout << a << " / " << b << " = " << a / b << endl;
    }
    return 0;
}