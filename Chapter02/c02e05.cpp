#include <iostream>
using namespace std;
int main(void)
{
    /////////////////////           a           //////////////////////////////
    cout << 'a' << endl;  // char, prints 'a'
    cout << L'a' << endl; // wchar_t, prints '97'
    cout << "a" << endl;  // const char[2], prints 'a'
    cout << L"a" << endl; // const wchar_t[2], prints '0x404004'

    /////////////////////           b           //////////////////////////////
    // 10, 10u, 10L, 10uL, 012, 0xC
    cout << 10 << endl;   // int, prints '10'
    cout << 10u << endl;  // unsigned int, prints '10'
    cout << 10L << endl;  // long int, prints '10'
    cout << 10uL << endl; // unsigned long int, prints '10'
    cout << 012 << endl;  // int, prints '10' because it is an octal literal,
    cout << 0xC << endl;  // int prints '12', because it is a hexadecimal literal,

    /////////////////////           c           //////////////////////////////
    // 3.14, 3.14f, 3.14L
    cout << 3.14 << endl;  // double, prints '3.14'
    cout << 3.14f << endl; // float, prints '3.14'
    cout << 3.14L << endl; // long double, prints '3.14'

    /////////////////////           d           //////////////////////////////
    // 10, 10u, 10., 10e-2
    cout << 10 << endl;    // int, prints '10'
    cout << 10u << endl;   // unsigned int, prints '10'
    cout << 10. << endl;   // double, prints '10'
    cout << 10e-2 << endl; // double, prints '0.1'

    return 0;
}