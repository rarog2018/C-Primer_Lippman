#include <iostream>

using namespace std;

int main()
{
    int a = 7, b = 11;
    int *p1 = &a, *p2 = &b;
    cout << "p1: " << p1 << ", p2: " << p2 << endl;
    // Pointers store addresses, so adding two addresses would result
    // (theoretically) in yet another address value that might or might
    // not be in  range of our computer's memory, but what would be the
    // point of doing so?
    // error: invalid operands of types 'int*' and 'int*' to binary 'operator+'|
    cout << "p1 + p2 = " << p1 + p2 << endl;

    return 0;
}
