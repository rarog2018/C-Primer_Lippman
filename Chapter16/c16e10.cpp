#include <iostream>
using namespace std;

// When the compiler instantiates a class from the class template, it rewrites
// the class template, replacing each instance of the template parameter T by
// the given template argument
// For example

template <typename T>
class Foo
{
public:
    T wha(T param) const { return param; }
};

int main(void)
{
    Foo<int> fi;
    // the compilator will rewrite our class as:
    /*
    template <> Foo<int>
    {
    public:
        int wha(int param) const { return param; }
    };
    */

    cout << fi.wha(15) << endl;
    cout << fi.wha('z') << endl;
    return 0;
}