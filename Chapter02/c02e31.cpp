#include <iostream>
using namespace std;

int main(void)
{
    int i = 0;
    // top-level const
    const int v2 = 0;
    // no const, because top-level const is ignored when copying an object
    int v1 = v2;
    // no const, although references are kind of always top-level const
    int *p1 = &v1, &r1 = v1;
    // p2 has low-level const, p3 has both top-level and low-level const
    // r2 has both top-level and low-level const
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;

    // top-level const of v2 is ignored when copying its value to the object
    // to which r1 is bound (which is v1), so it is legal
    r1 = v2;

    // it is illegal because low-level const must match and here p2 has low-level
    // const and p1 does not
    // p1 = p2;

    // legal, p2 does not have top-level const so we can assign it to a new object
    // p1 is a plain nonconst pointer, and nonconst can be converted to const
    p2 = p1;

    // illegal, we can ignore top-level const of p3, but we cannot ignore
    // low-level const of p3; p1 is does not have low-const so we cannot convert
    // const of p3 to nonconst
    // p1 = p3;

    // legal, p2 does not have top-level const so we can assign it to a new object
    // and top-level const of p3 is ignored while copying (the address),
    // both pointers have matching low-level const
    p2 = p3;
    cout << p2 << " " << p3 << " " << &i << endl; // all point to the same address
    return 0;
}