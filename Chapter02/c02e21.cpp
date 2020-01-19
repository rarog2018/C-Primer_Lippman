#include <iostream>
using namespace std;

int main(void)
{
    int i = 0;
    /////////////////////           a           //////////////////////////////
    // illegal, the pointer's type must match the type of the object that it
    // points to (if it is not a void pointer)
    // double *dp = &i;

    /////////////////////           b           //////////////////////////////
    // illegal, pointer cannot be initialized with an int value
    // int *ip = i;

    /////////////////////           c           //////////////////////////////
    // legal, p which is a pointer to int ineed points to an int object
    int *p = &i;

    return 0;
}