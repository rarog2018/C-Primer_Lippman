#include <iostream>
using namespace std;

class numbered
{
public:
    static unsigned val;
    numbered();                 // default constructor
    numbered(const numbered &); // copy constructor
    const unsigned mysn;
};

unsigned numbered::val = 0;

// copy constructor definition
numbered::numbered(const numbered &orig) : mysn(++val)
{
    cout << "Using copy constructor" << endl;
}

// default constructor definition
numbered::numbered() : mysn(++val)
{
    cout << "Using default constructor" << endl;
}

void f(numbered s) { cout << s.mysn << endl; }
int main(void)
{
    // Adding copy constructor does change the output, so now the serial numbers
    // are indeed unique, but because function 'f', parameter is not a reference
    // the copy constructor is also used when the function is called, so the
    // values are not what we expected
    // we wanted 1, 2, 3 to be printed, instead 4, 5, 6 is printed
    // 'f' prints the values of temp objects created when function is called
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    // the value below is correct (1)
    cout << "a.mysn = " << a.mysn << endl;
    return 0;
}