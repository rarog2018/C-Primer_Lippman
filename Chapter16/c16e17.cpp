#include <iostream>
#include <string>
using namespace std;

class Example
{
public:
    typedef double size_type;

    size_type size() { return 17.555; }
};

// in almost all the cases there is no difference between using 'typename' or
// 'class' keywords to declare a type parameter

// sometimes we have to inform the compiler that a name represents a type for
// example te following function needs 'typename' not 'class' because the
// return type is not a class type

template <typename T>
typename T::size_type f(T &ob)
{
    return ob.size();
}

int main(void)
{
    string abc("hello");
    Example xyz;

    cout << f(abc) << endl; // size_type is long long unsigned int
    cout << f(xyz) << endl; // size_type is double
    return 0;
}