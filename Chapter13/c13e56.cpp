#include <iostream>
using namespace std;

// this function will cause an error, because on the return line it will call
// itself infinitely
// 'ret' is an lvalue, so when we call ret.sorted() it calls the function
// 'sorted() const &', which creates another lvalue object ret, which calls
// this function inside again, and again and again
Foo Foo::sorted() const &
{
    Foo ret(*this);
    return ret.sorted();
}

int main(void)
{
    return 0;
}