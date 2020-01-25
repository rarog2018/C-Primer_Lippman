#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // illegal, cannot bind non-const lvalue reference of type int& to an
    // rvalue of type int
    // r would have to be a reference to const
    // int i = -1, &r = 0;

    /////////////////////           b           //////////////////////////////
    // legal, p2 is a const pointer that will always point to i2
    // int i2 = 5;
    // int *const p2 = &i2;

    /////////////////////           c           //////////////////////////////
    // legal, because r is a reference to const, i is a const integer
    // const int i = -1, &r = 0;

    /////////////////////           d           //////////////////////////////
    // legal p3 is a const pointer to const int, it cannot change to what it is
    // pointing and it cannot change the value of the object to which it points
    // const int *const p3 = &i2;

    /////////////////////           e           //////////////////////////////
    // legal, p1 is a pointer to (what it thinks it is) const int
    // const int *p1 = &i2;

    /////////////////////           f           //////////////////////////////
    // illegal r2 wants to be const reference to a const int, but it needs to
    // be initialized
    // const int &const r2;

    /////////////////////           g           //////////////////////////////
    // legal, i2 is a const int, and r is a reference to const int bound to i
    const int i = -1;
    const int i2 = i, &r = i;

    return 0;
}