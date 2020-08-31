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

void calc(int);
void calc(LongDouble);

int main(void)
{
    double dval;

    // calls the calc(int) version because promoting double to int has priority
    // in the conversion hierarchy, and it doesn't require user-defined conversion
    calc(dval); // which calc?
    return 0;
}

void calc(int v)
{
    cout << "value: " << v << endl;
}
void calc(LongDouble v)
{
    cout << "LongDouble value: " << v.val << endl;
}
