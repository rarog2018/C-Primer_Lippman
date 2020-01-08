#include <iostream>

using namespace std;

int main(void)
{
    int i;
    double d;
    d = i = 3.5;
    // assignment is right associative so first 3.5 will
    // be assigned to i, but because i is an integer it
    // will be truncated, so the value stored in i will be
    // 3, and this is the value that will be assigned to d
    cout << "d: " << d << ", i: " << i << endl;

    // 3.5 will be assigned to d, and then the value of d
    // which is 3.5 will be truncated to 3, because i is an int
    i = d = 3.5;
    cout << "d: " << d << ", i: " << i << endl;
}
