#include <iostream>
using namespace std;

int main(void)
{
    int i;
    // int *const cp;       // illegal
    int *p1;
    // int *const p2;       // illegal
    // const int ic;        // illegal
    // const int &r = ic;   // illegal
    // const int *const p3; // illegal
    const int *p;

    /////////////////////           a           //////////////////////////////
    // it is an error, because ic is not initialized
    // although if 'ic' was initialized it would be legal, we would just assign
    // the value of ic to i variable
    // i = ic;

    /////////////////////           b           //////////////////////////////
    // it is an error, because p3 is not initialized, and it is illegal because
    // it is not possible to assign the address of a pointer to const to a plain
    // pointer, no matter if it really points to a const or not
    // p1 = p3;

    /////////////////////           c           //////////////////////////////
    // it is an error because ic is not initialized, and even if it was
    // initialized it is illegal, because it is not possible to assign the
    // address of a pointer to const object to a plain pointer
    // p1 = &ic;

    /////////////////////           d           //////////////////////////////
    // it is an error because ic and p3 are not initialized,
    // if ic and p3 were initialized it would be illegal, because p3 is a const
    // pointer so it cannot change the object to which it points, however
    // if ic was initialized, we could initialize p3 from ic
    // const int *const p3 = &ic; // legal if ic initialized
    // p3 = &ic;    // illegal

    /////////////////////           e           //////////////////////////////
    // it is an error because p2 is not initialized
    // if it was initialized it would be illegal, because p2 is a const pointer
    // it can be initialized with an address but cannot be assigned to new one
    // p2 = p1;

    /////////////////////           f           //////////////////////////////
    // it is an error because both ic and p3 are not initialized
    // it would be illegal even if both were initialized, because ic is not
    // a modificable l-value, it cannot be assigned to a new value after
    // initialization, hovewer we could initialize ic from the value underneath *p3
    // const int ic = *p3;  // legal if p3 initialized
    // ic = *p3; // illegal

    return 0;
}