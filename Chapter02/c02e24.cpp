#include <iostream>
using namespace std;

int main(void)
{
    int i = 42;
    // void pointer can hold the address of any object
    void *p = &i;
    // the pointer to long cannot be initialized with the address of int
    // long *lp = &i;
    cout << "long: " << sizeof(long) << " int: " << sizeof(int) << endl;
    // if it was possible the result would be catastrophic, because lp would
    // point to the chunk of memory that is outside of int object to which it
    // points
    return 0;
}