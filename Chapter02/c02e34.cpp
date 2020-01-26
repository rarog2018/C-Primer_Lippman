#include <iostream>
using namespace std;

int main(void)
{
    // setup
    int i = 0, &r = i;
    auto a = r; // a is an int (r is an alias for i, which has type int)
    const int ci = i, &cr = ci;
    auto b = ci;       // b is an int (top-level const in ci is dropped)
    auto c = cr;       // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i;       // d is an int*(& of an int object is int*)
    auto e = &ci;      // e is const int*(& of a const object is low-level const)
    const auto f = ci; // deduced type of ci is int; f has type const int
    auto &g = ci;      // g is a const int& that is bound to ci
    // auto &h = 42;      // error: we can't bind a plain reference to a literal
    const auto &j = 42; // ok: we can bind a const reference to a literal

    ///////////////////////         ANSWER          //////////////////////////
    // a is an int so the value 42 is assigned to it
    a = 42;
    cout << "a: " << a << endl;
    // b is an int, the value 42 is correctly assigned to it
    b = 42;
    cout << "b: " << b << endl;
    // c is an int, the value 42 is correctly assigned to it
    c = 42;
    cout << "c: " << c << endl;
    // d is a pointer to int, we cannot assign a value of type int to a pointer
    // d = 42;  // error: invalid conversion from 'int' to 'int*'

    // e is a pointer to const int, we cannot assign a value of type int to a pointer
    // e = 42;  // error: invalid conversion from 'int' to 'const int*'

    // g is a reference to const int and is already bound to 'ci', so we cannot
    // assign a value to it
    // g = 42;  // error: assignment of read-only reference 'g'

    return 0;
}