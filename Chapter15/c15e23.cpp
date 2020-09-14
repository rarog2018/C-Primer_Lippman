#include <iostream>
using namespace std;

class Base
{
public:
    virtual int fcn();
};

class D1 : public Base
{
public:
    // hides fcn in the base; this fcn is not virtual
    // D1 inherits the definition of Base::fcn()
    // int fcn(int);      // parameter list differs from fcn in Base
    // fix: remove the int parameter, add override keyword
    int fcn() override;
    virtual void f2(); // new virtual function that does not exist in Base
};

int main(void)
{
    Base bobj;
    D1 d1obj;
    Base *pb = &d1obj;
    cout << bobj.fcn() << endl;
    cout << d1obj.fcn() << endl;
    cout << endl;

    // because fcn() is virtual it will call D1::fcn() even though the pointer
    // static type is Base *
    cout << pb->fcn() << endl;
    return 0;
}

// Base definitions
inline int Base::fcn()
{
    return 7;
}

// D1 definitions
inline int D1::fcn()
{
    return 15;
}

inline void D1::f2()
{
    cout << "D1::f2()" << endl;
}