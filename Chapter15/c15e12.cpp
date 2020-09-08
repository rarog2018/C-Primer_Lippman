#include <iostream>
using namespace std;

// It might be useful when f.e. we extend the base class to a certain degree in
// the derived class and we know that all other extensions in the inheritance
// hierarchy will be cosmetics or technical details, so the function from this
// particular derived class will be valid for all other classes in the inheritance
// hierarchy

// F.e
// class LivingThings { virtual void display_cell();}
// class Plants: public LivingThings { void display_cell() override final;}
// adds chlorofile information or something
// class Rose { /* ... */ } // doesn't need separate display, because the plant
// one is sufficient

int main(void)
{
    return 0;
}