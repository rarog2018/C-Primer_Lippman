#include <iostream>

using namespace std;

int main(void)
{
    short a = 32767;
    short b = a + 1;
    cout << "Short " << a << " + 1 is equal: " << b << endl;
    unsigned c = 0;
    unsigned d = c - 1;
    cout << "Unsigned " << c << " - 1 is equal: " << d << endl;
    short e = -a;
    short f = e - 2;
    cout << "Short " << e << " - 2 is equal: " << f << endl;
}
