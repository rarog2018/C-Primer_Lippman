#include <iostream>
using namespace std;

class Base
{
    ...
};

// a) class Derived : public Derived { ... };
// This is incorrect, because the class cannot inherit from itself, because it
// must be DEFINED before we can inherit from it

// b) class Derived : private Base { ... };
// Correct

// c) class Derived : public Base;
// Incorrect, because this is a declaration, not a definiton. When we declare
// a class we do not include its derivation list

int main(void)
{
    return 0;
}