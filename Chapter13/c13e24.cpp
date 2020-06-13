#include <iostream>
using namespace std;

// destructor: if HasPtr didn't define a destructor the dynamically allocated
// memory for the string member would not be freed
// copy constructor: if HasPtr didn't define a copy constructor the string
// member of the new object would use the same memory as the original object,
// so the changes to the original object would also change the copy

int main(void)
{
    return 0;
}