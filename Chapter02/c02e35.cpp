#include <iostream>
using namespace std;

int main(void)
{
    const int i = 42;
    // j is a plain int, top-level const is omitted
    auto j = i;
    cout << "j: " << j << endl;
    j += 35;
    cout << "j after addition: " << j << endl;

    // k is a reference to const int, low-level const is not ignored when
    // we ask for a reference to an auto-deduced type
    // the const qualifier before auto does pretty much nothing because
    // references are anyway bound to their objects
    const auto &k = i;
    // k = 15;  // error

    // p is a nonconst pointer to const int, low-level const is not ignored
    auto *p = &i;
    cout << "*p: " << *p << endl;
    // *p = 77; // error: assignment of read-only location '* p'
    p = &j; // ok p is a nonconst pointer, we can assign it to other addresses

    // j2 is a const int, k2 is a reference to const int - same as '&k'
    const auto j2 = i, &k2 = i;
    // j2 = 55; // error
    return 0;
}