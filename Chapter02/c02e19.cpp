#include <iostream>
using namespace std;

int main(void)
{
    // pointer is an object on its own, while reference is just a type alias
    // pointer does not need to be initialized when it is defined
    // pointer can point to different objects in its lifetime, while reference
    // is bind to its initial object
    // pointer has its own address in the memory, reference does not
    int x = 5;
    int &rx = x;
    int *px = &x;
    cout << "address of x: " << &x << endl;
    cout << "address of &rx: " << &rx << endl; // the same as x
    cout << "address of *px: " << &px << endl;
    cout << "size of x " << sizeof(x) << " size of px " << sizeof(px) << endl;
    return 0;
}