#include <iostream>
using namespace std;

class numbered
{
public:
    static unsigned val;
    numbered() : mysn(++val) {}                 // default constructor
    numbered(const numbered &) : mysn(++val) {} // copy constructor
    const unsigned mysn;
};

unsigned numbered::val = 0;

void f(const numbered &s) { cout << s.mysn << endl; }
int main(void)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}