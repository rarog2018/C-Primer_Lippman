#include <iostream>

using namespace std;
int main(void)
{
    int a = 5;
    auto flag = [&a] { return --a < 0 ? false : true; };
    while (flag())
    {
        cout << a << " ";
    }
    return 0;
}