#include <iostream>
#include <string>

using namespace std;
/////////////////       a       /////////////////
// the return types do not match, the return type should be string or function
// should return an int
// int f()
string f()
{
    string s;
    // ...
    return s;
}

/////////////////       b       /////////////////
// function does not have a return type
// f2(int i)
void f2(int i)
{ /* ... */
}

/////////////////       c       /////////////////
// code block lacks opening parenthesis and the parameter names are duplicated
// there will be also a warning because in this implementation the function
// does not return an int (but maybe it is inside /*...*/)
// int calc(int v1, int v1)
int calc(int v1, int v2)
{ /* ... */
}

/////////////////       d       /////////////////
// return statement has to be inside a curly bracket block
// double square(double x) return x * x;
double square(double x)
{
    return x * x;
}

int main(void)
{
    int i = 0;
    f();
    f2(i);
    calc(i, i);
    square(i);
    return 0;
}