#include <iostream>
using namespace std;

int main(void)
{
    // a) % it should be a class member, because it does not work with mixed
    // types
    // auto a = 5.4 % 2; error

    // b) %= it should be a class member, because all compound assignment operators
    // should ordinarily be class members, and as we saw earlier % doesn't work
    // with mixed types

    // c) ++ should be a class member, because it changes the state of the object
    // and it is closely tied to the given type

    // d) -> should be a class member, it is closely tied to the given type, it
    // even MUST be a class member

    // e) << should not be a class member, because it converts the given type
    // to an ostream object

    // f) && it doesn't need to be a class member, because it returns bool

    // g) == it shouldn't be a class member, because it returns bool

    // h) () it must be a class member

    return 0;
}