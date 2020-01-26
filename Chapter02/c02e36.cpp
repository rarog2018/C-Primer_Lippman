#include <iostream>
using namespace std;

int main(void)
{
    int a = 3, b = 4;
    // c is a plain int
    decltype(a) c = a;
    // d is a reference to int bound to 'a'
    decltype((b)) d = a;

    ++c; // c = 4, while a is still 3
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    ++d; // a is incremented, a = 4
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "address of a = " << &a << ", address of d = " << &d << endl;
    return 0;
}