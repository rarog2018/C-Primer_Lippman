#include <iostream>
using namespace std;

// for me it looks like the same will happen as in the exercise 56, it will cause
// an infinite recursion for exactly the same reasons

// but actually i was wrong, Foo(*this) is not a variable (hence it is not an
// lvalue), so it is in fact an rvalue, which will use std::move(), so the call
// Foo(*this).sorted() will use the && version of sorted()
Foo Foo::sorted() const & { return Foo(*this).sorted(); }

int main(void)
{
    return 0;
}