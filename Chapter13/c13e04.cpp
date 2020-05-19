#include <iostream>
using namespace std;

class Point;

Point global;
Point foo_bar(Point arg) // copy constructor used to initialize the parameter
{
    // copy constructor used to initialize dynamically allocated object, to
    // which 'heap' points
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap}; // might use copy constructor
    return *heap;                 // copy constructor might be used, because the function re
    // turns a copy, not a reference
}

int main(void)
{
    return 0;
}