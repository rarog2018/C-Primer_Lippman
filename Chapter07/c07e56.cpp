#include <iostream>
using namespace std;

// 'static' class member is a member that is associated with the class not its
// objects. This means that objects of that class type do not contain the data
// of static members. Static functions do not have 'this' pointer.

// Advantages: all objects of that class type can use the data provided by a
// static member, that data is the same for all the objects, because there is
// only one 'instantion' of that static member instead of 'n' instantions for
// each object.
// This also means that when we change the data in the static member, all objects
// will use the new, updated value.
// static member can have incomplete type and it can be used as a default argument

int main(void)
{
    return 0;
}