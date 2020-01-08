#include <iostream>

using namespace std;
void reset(int &n);
int main(void)
{
    int a = 21;
    cout << "before reset a = " << a << endl;
    reset(a);
    cout << "after reset a = " << a << endl;
    return 0;
}
// function takes a reference to an int object
void reset(int &n)
{
    // and changes its value to 0
    n = 0;
}