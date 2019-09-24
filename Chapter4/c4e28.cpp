#include <iostream>

using namespace std;

int main(void)
{
    cout << "Size of: (in bytes)\n" << "short int: " << sizeof (short)
        << "\nint: " << sizeof (int) << "\nlong int: " << sizeof (long int)
        << "\nlong long int: " << sizeof (long long int) << "\nfloat: "
        << sizeof (float) << "\ndouble: " << sizeof (double) << "\nlong double: "
        << sizeof (long double) << "\nchar: " << sizeof (char)
        << "\nwchar_t: " << sizeof (wchar_t) << endl;
}
