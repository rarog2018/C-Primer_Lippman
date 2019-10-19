#include <iostream>

using namespace std;
// function takes a reference instead of pointers
void swap(int &a, int &b);
int main(void)
{
    int a = 5, b = 17;
    // this line is no longer needed, because we pass the objects directly
    // int *pa = &a, *pb = &b;
    cout << "Before swap: a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << " b = " << b << endl;

    return 0;
}
// for me its easier and more readable to use references instead of pointers
void swap(int &a, int &b)
{
    // we no longer need to use dereference operator
    int temp = a;
    a = b;
    b = temp;
}