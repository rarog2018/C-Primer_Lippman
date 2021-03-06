#include <iostream>
using namespace std;

// instantiation is a class or function generated by the compiler from a template
// for example
template <typename T>
T result(const T &v1, const T &v2)
{
    return v1 + v2;
}

int main(void)
{
    // instantiates: int result(const int &, const int &)
    cout << result(15, 3) << endl;
    // instantiates: double result(const double &, const double &)
    cout << result(12.7, 13.9) << endl;
    return 0;
}