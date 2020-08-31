#include <iostream>
using namespace std;

struct LongDouble
{
    LongDouble(double a = 0.0) : val(a) {}
    operator double()
    {
        cout << "using double()" << endl;
        return 0.0;
    }
    operator float()
    {
        cout << "using float()" << endl;
        return 0.0;
    };
    long double val;
};

int main(void)
{
    LongDouble ldObj;
    // error: there is more than one possible conversion from LongDouble to int
    // both operator double() and operator float() can be used to promote ldObj
    // to int, so the call is ambiguous
    // int ex1 = ldObj;

    // ok, uses operator float() to convert LongDouble to float
    float ex2 = ldObj;
}