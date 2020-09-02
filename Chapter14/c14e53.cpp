#include <iostream>
using namespace std;

class SmallInt
{
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

public:
    SmallInt(int = 0);                   // conversion from int
    operator int() const { return val; } // conversion to int
private:
    std::size_t val;
};

int main(void)
{
    SmallInt s1;
    // it is not legal, because a built-in + and the SmallInt operator+ can
    // be used
    // to fix this we can use 3.14 as a value for the constructor of the
    // SmallInt object: SmallInt(3.14)
    // or cast s1 to double: static_cast<double>(s1)
    // double d = s1 + 3.14;
    return 0;
}