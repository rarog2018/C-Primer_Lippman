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

    // regular member functions, that set the values of its members
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }

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