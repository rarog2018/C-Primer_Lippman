#include <iostream>
#include <vector>
using namespace std;

class Example
{
public:
    // error, if we want to initialize a static member inside a class, it has
    // to be a const member
    static double rate = 6.5;
    // static const double rate = 6.5; // ok
    // static double rate; // also ok

    // legal, because the variable is const
    static const int vecSize = 20;

    // error, parentheses cannot be used as an in-class initializer
    // and again as in the first definition, nonconst static members should be
    // initialized outside of the class
    static vector<double> vec(vecSize);
    // static vector<double> vec; // ok
};

// it is technically not an error, but it should initialize the static member
double Example::rate;
// duble Example::rate = 6.5;  // would be ok

// same as above, it should initialize this member
vector<double> Example::vec;
// vector<double> Example::vec(Example::vecSize); // would be ok
int main(void)
{
    return 0;
}