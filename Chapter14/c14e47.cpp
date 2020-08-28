#include <iostream>
using namespace std;

struct Integral
{
    operator const int(); // converts (and possibly change) Integral to const int
    operator int() const; // converts (unchangeable) const Integral to int
};

int main(void)
{
    return 0;
}