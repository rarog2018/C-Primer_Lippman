#include <iostream>
using namespace std;

// Which are true
// (a) A class must provide at least one constructor.
// True, even if we omit it, there will be a syntesized default constructor

// (b) A default constructor is a constructor with an empty parameter list.
// False. Constructor that has an empty parameter list is a default
// constructor, but a constructor whose all parameters are default parameters
// is also a default constructor.

// (c) If there are no meaningful default values for a class, the class should not
// provide a default constructor.
// False, the default constructor should be always provided, especially if we
// already defined another constructor.

// (d) If a class does not define a default constructor, the compiler generates
// one that initializes each data member to the default value of its associated
// type.
// False. Compiler generates a synthesized default constructor ONLY when there
// is no other constructor.

int main(void)
{
    return 0;
}