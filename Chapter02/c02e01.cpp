#include <iostream>
using namespace std;
int main(void)
{
    // short, int, long, long long represent integer values of (potentially)
    // different sizes: it is guarenteed that int will be at least as large
    // as short, long at least as large as int, long long at least as large
    // as long
    cout << "Type\t\tSize (in bytes)" << endl;
    cout << "short\t\t" << sizeof(short) << endl;
    cout << "int\t\t\t" << sizeof(int) << endl;
    cout << "long\t\t\t" << sizeof(long) << endl;
    cout << "long long\t\t" << sizeof(long long) << endl;

    // float and double represent floating-point values of (potentially)
    // different sizes: it is guaranteed that float will represent at least
    // 6 significant digits, double at least 10 significant digits
    // typically float is represented in one word - 32 bits (4 bytes),
    // double in two words - 64 bits (8 bytes)
    cout << "float\t\t" << sizeof(float) << endl;
    cout << "double\t\t" << sizeof(double) << endl;
    cout << "long double\t" << sizeof(long double) << endl;

    // unsigned type represents only values equal to or greater than zero, all
    // the bits represent the value,
    // signed type represents positive or negative values, one bit represents
    // the sign of the value

    /* On my computer
    Type		Size (in bytes)
    short		    2
    int			    4
    long		    4
    long long		8
    float		    4
    double		    8
    long double	    16
    */
    return 0;
}