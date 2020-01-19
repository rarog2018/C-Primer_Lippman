#include <iostream>
using namespace std;

int main(void)
{
    int x = 0;
    int *p = &x;
    // if the pointer is not a null pointer the condition is true
    if (p)
    {
        cout << "p" << endl;
    }
    else
    {
        cout << p << endl;
    }
    // is true if the value to which pointer points is nonzero
    if (*p)
    {
        cout << "*p" << endl;
    }
    else
    {
        cout << *p << endl;
    }
    return 0;
}