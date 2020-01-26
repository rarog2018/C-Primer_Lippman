#include <iostream>
using namespace std;

int main(void)
{
    int a = 3, b = 4;
    // c is a plain int with the value that 'a' yields which is 3
    decltype(a) c = a;
    // d is a reference to int, bound to 'a', 'a' is still 3, the assignment
    // expression inside the paretheses is not evaluated
    decltype(a = b) d = a;
    cout << "address of a = " << &a << ", address of d = " << &d
         << ", address of c =" << &c << endl;
    cout << "c = " << c << ", d = " << d << endl;
    return 0;
}