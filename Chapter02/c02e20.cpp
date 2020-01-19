#include <iostream>
using namespace std;

int main(void)
{
    // define and initialize i to 42
    int i = 42;
    // define and initialize a pointer p1 to point to the address of i
    int *p1 = &i;
    // dereference p1 and assign to it the value returned by dereferencing p1
    // multiplied by the value dereferenced by p1
    // so i = 42 * 42
    *p1 = *p1 * *p1;
    cout << *p1 << endl;
    return 0;
}