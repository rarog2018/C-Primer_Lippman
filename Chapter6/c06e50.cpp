#include <iostream>

using namespace std;
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
int main(void)
{
    ///////////////////////         a           ///////////////////////
    // The call is ambigous => f(double, double = 3.14) is exact match for first
    // argument and second argument can be converted to doulbe, but f(int, int)
    // is exact match for second argument and first argument can be converted
    // to int
    // error: call of overloaded 'f(double, int)' is ambiguous
    // f(2.56, 42);

    ///////////////////////         b           ///////////////////////
    // There are two viable functions: f(int) which is an exact match, and
    // f(double, double = 3.14) in which second argument is a default argument
    // so it does not ned to appear in the call and first argument can be
    // converted to double
    // The best match is f(int)
    f(42);

    ///////////////////////         c           ///////////////////////
    // There are two viable functions: f(int, int) which is an exact match,
    // and f(double, double = 3.14) in which both arguments can be converted
    // from int to double
    // The best match is f(int, int)
    f(42, 0);

    ///////////////////////         d           ///////////////////////
    // There are two viable functions: f(double, doybke) which is an exact match,
    // and f(int, int) in which both arguments can be converted from double to int
    // The best match is f(double, double = 3.14)
    f(2.56, 3.14);
    return 0;
}

void f()
{
    cout << "Hello" << endl;
}
void f(int)
{
    cout << "World" << endl;
}
void f(int, int)
{
    cout << "Hello, world" << endl;
}
void f(double, double)
{
    cout << "Hello, world!" << endl;
}