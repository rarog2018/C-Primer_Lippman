#include <iostream>
using namespace std;

// rvalue reference refers to a temporary object, that is about to be destroyed
// lvalue reference refers to a persistent object
// for example variables are lvalues and can be referred to by lvalue reference
// the values of the variables can be rvalues:
// int i = 42;  variable i is an lvalue, the expression 42 is an rvalue
// cout << i * 2 << endl; the expression i * 2 is a temporary object, an rvalue
// we can catch such object to an rvalue reference:
// int &&rr = i * 2;
// we can also use library function std::move to cast an lvalue to an rvalue
// reference type, but after that we cannot use i in the current state, we have
// to either destroy it or assign new value to it
// int &&rr2 = std::move(i);

int main(void)
{
    return 0;
}