#include <iostream>

using namespace std;
// Candidate function is a function with the same name as the called function
// and for which a declaration is visible at the point of the call

// Viable function is a candidate function that can be called with the argu-
// ments in the given call

// All three functions below are candidates for call f(5)
void f();       // not viable function - number of arguments doesn't match
void f(int a);      // viable function (exact match)
void f(double a);   // viable function - 5 can be converted to double
int main(void)
{
    f(5);
    return 0;
}