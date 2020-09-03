#include <iostream>
using namespace std;

// virtual member is a function that is preceeded by the 'virtual' keyword
// it is declared in the base class and its expected to be overrided in the
// derived class

class BaseClassN
{
public:
    virtual void member1();
};

class DerivedClassN : public BaseClassN
{
public:
    void member1() { cout << "Overriding member1 from the base class" << endl; }
};

void caller(BaseClassN &o)
{
    o.member1(); // decides to use proper version of member1 at runtime
}
int main(void)
{
    DerivedClassN obj;
    caller(obj); // works even though, the type is not BaseClassN
    return 0;
}