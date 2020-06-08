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

void f(const numbered &s) { cout << s.mysn << endl; }
int main(void)
{
    // changing parameter from (numbered s) to (const numbered &s) changes the
    // output, because now, the temporary objects are not created, instead
    // the original ones are used inside the function body
    // the output is as expected and intended
    numbered a, b = a, c = b;
    f(a); // 1
    f(b); // 2
    f(c); // 3
    // the value below is correct (1)
    cout << "a.mysn = " << a.mysn << endl;
    return 0;
}