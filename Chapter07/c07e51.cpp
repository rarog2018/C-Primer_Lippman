#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    // string is an array of n elements of type char, which is exactly what
    // a string literal is, therefore its single-argument constructor does
    // not need to be explicit
    string s = "abc";

    // vector on the other hand is a container of n elements of type T, which
    // is not the same as a single value of that type, therefore its single-
    // argument constructor is explicit. Not to mention that constructing a
    // vector from a single parenthesized value means the number of values
    // of certain type rather than a number as a value.
    // vector<int> a = 15; // error
    return 0;
}