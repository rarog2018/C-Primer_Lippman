#include <iostream>

using namespace std;
// this version of function f() creates a copy of an argument that is passed
// to it
void f(int a);

// this version takes a reference to the passed argument, so it operates on
// original object instead of its copy
void f(int &a);
int main(void)
{
    return 0;
}