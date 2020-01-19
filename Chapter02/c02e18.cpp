#include <iostream>
using namespace std;

int main(void)
{
    int x = 5, y = 8;
    int *pi = &x;
    cout << "pi points to " << pi << " which has value " << *pi << endl;
    pi = &y; // change the value of a pointer
    cout << "pi points to " << pi << " which has value " << *pi << endl;
    *pi = 11; // change the value to which the pointer points
    cout << "pi points to " << pi << " which has value " << *pi << endl;

    return 0;
}