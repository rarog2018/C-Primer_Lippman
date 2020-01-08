#include <iostream>

using namespace std;
int f();
int main(void)
{
    for (int i = 0; i != 8; ++i)
    {
        cout << f() << " ";
    }
    cout << endl;
    return 0;
}
int f()
{
    static int n = 0;
    return n++;
}