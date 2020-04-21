#include <iostream>
using namespace std;

// The function, when called will be a source of a memory leak
// It creates a dynamically allocated object of type int and uses a built-in
// pointer to manage that object. Because it returns a bool value, instead of
// a pointer to that memory, after the function is done there will be no way to
// access that memory, because the 'p' pointer will be destroyed.
bool b()
{
    int *p = new int;
    // ...
    return p;
}

int main(void)
{
    return 0;
}