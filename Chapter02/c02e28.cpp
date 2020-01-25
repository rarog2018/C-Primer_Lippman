#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // illegal, cp is a const pointer to int it must be initialized
    // int i, *const cp;

    /////////////////////           b           //////////////////////////////
    // illegal, p1 is a pointer to int (it is ok), p2 is a const pointer to
    // int, it must be initialized
    // int *p1, *const p2;

    /////////////////////           c           //////////////////////////////
    // illegal, ic is a const int it has to be initialized, r is a reference
    // to const int so it cannot change the value in the address that it is
    // bound to
    // const int ic, &r = ic;

    /////////////////////           d           //////////////////////////////
    // illegal, p3 is a const pointer to const int it has to be initialized
    // const int *const p3;

    /////////////////////           e           //////////////////////////////
    // legal, p is a (plain) pointer to const int
    const int *p;
    return 0;
}