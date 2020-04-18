#include <iostream>
using namespace std;

class Debug
{
public:
    // constructors canot have return statement
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {} // default c.
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    // constexpr member function that checks if any member is true, return is
    // the only executable statement that it can have
    constexpr bool any() { return hw || io || other; }

    ///////////////////////////////////////////////////////////////////////////
    // should these functions be declared as constexpr?
    // They should not, because all of them have assignment statement in their
    // function bodies, and (as stated above) the only statement that constexpr
    // functions can have is a return statement
    // although as we can see by executing this code, setting these functions
    // as constexpr, not only does not generate a compilator error, but seems
    // to work exactly the same way as versions without 'constexpr'
    constexpr void set_io(bool b) { io = b; }
    constexpr void set_hw(bool b) { hw = b; }
    constexpr void set_other(bool b) { hw = b; }
    ///////////////////////////////////////////////////////////////////////////

private:
    // members that imitate error-states
    bool hw;    // hardware errors other than IO errors
    bool io;    // IO errors
    bool other; // other errors
};

int main(void)
{
    Debug obj1; // generated with default constructor, all members true
    cout << obj1.any() << endl;

    Debug obj2(false, false, false);
    cout << obj2.any() << endl;

    obj2.set_hw(true);
    cout << obj2.any() << endl;

    return 0;
}