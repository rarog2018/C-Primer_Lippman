#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // it is a string literal (const char[]),that contains two escape sequence
    // each with three octal digits
    // prints "Who goes with Fergus?" followed by new line ("\012")
    cout << "Who goes with F\145rgus?\012" << endl;

    /////////////////////           b           //////////////////////////////
    // the type is long double, it uses expotent so it is pretty much 3.14 * 10^1
    // so it prints '31.4' as expected
    cout << 3.14e1L << endl;

    /////////////////////           c           //////////////////////////////
    // this probably worked on previous C++ versions or maybe it is a compiler
    // thing but it produces error: unable to find numeric literal operator 'operator""f'
    // it should be just a value of type float, but apparently we have to add
    // the dot after the literal
    // cout << 1024f << endl; // generates error
    cout << 1024.f << endl; // correctly prints 1024

    /////////////////////           d           //////////////////////////////
    // the type is long double, prints '3.14'
    cout << 3.14L << endl;

    return 0;
}