#include <iostream>

using namespace std;
////////////////////        a       ////////////////////
// calc takes 2 int parameters and returns int
int calc(int, int);
// this version of calc takes 2 const int parameters and returns int
// it it illegal because it redefines previously defined function,
// top-level const has no effect on the objects that can be passed to a function
// which means that it is getting ignored, which means that both declarations
// are identical
int calc(const int, const int);

////////////////////        b       ////////////////////
// get takes no arguments and returns int
int get();
// get takes no arguments and returns double
// it is illegal because only the type is different while the parameter lists
// are the same
double get();

////////////////////        c       ////////////////////
// reset takes one parameter that is a pointer to int and returns a pointer
// yo int
int *reset(int *p);
// this version of reset takes one parameter that is a pointer to double and
// returns a pointer to double
// it is legal, because the type of the parameter is different than in previous
// declaration
double *reset(double *p);

int main(void)
{
    int x = 5;
    int *a = &x;
    double y = 5.12;
    double *b = &y;
    int *c = reset(a);
    double *d = reset(b);
    cout << c << " " << &x << endl;
    cout << d << " " << &y << endl;
    return 0;
}

int *reset(int *p)
{
    return p;
}
double *reset(double *p)
{
    return p;
}