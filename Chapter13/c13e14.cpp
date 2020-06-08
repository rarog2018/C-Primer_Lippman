#include <iostream>
using namespace std;

class numbered
{
public:
    static unsigned val;
    numbered(); // default constructor
    const unsigned mysn;
};

unsigned numbered::val = 1;
numbered::numbered() : mysn(val)
{
    ++val;
    cout << "Using default constructor" << endl;
}

void f(numbered s) { cout << s.mysn << endl; }
int main(void)
{
    // all serial numbers will be the same, because default constructor is
    // used only for 'a', 'b' and 'c' use synthesized assignment
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}