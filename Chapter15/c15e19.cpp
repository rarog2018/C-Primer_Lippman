#include <iostream>
using namespace std;

class Base
{
public:
    void pub_mem(); // public member

protected:
    int prot_mem = 17; // protected member
private:
    char priv_mem = 'z'; // private member
};

struct Pub_Derv : public Base
{
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // Legal
    void memfcn(Base &b) { b = *this; }
    // error: private members are inaccessible to derived classes
    // char g() { return priv_mem; }
};

struct Priv_Derv : private Base
{
    // private derivation doesn't affect access in the derived class
    int f1() const { return prot_mem; }
    // Legal
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
    // private derivation doesn't affect access in the derived class
    int f2() const { return prot_mem; }
    // Legal
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    // ok: Base::prot_mem remains protected in Pub_Derv
    int use_base() { return prot_mem; }
    // Legal
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
    // error: Base::prot_mem is private in Priv_Derv
    // int use_base() { return prot_mem; }
    // Illegal, no access to Base::Base, conversion to Base is illegal
    // void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv
{
    // ok: Base::prot_mem remains protected in Prot_Derv
    int use_base() { return prot_mem; }
    // Legal
    void memfcn(Base &b) { b = *this; }
};

int main(void)
{
    Base ob;
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    d1.memfcn(ob);
    d2.memfcn(ob);
    d3.memfcn(ob);
    dd1.memfcn(ob);
    dd3.memfcn(ob);
    return 0;
}

inline void Base::pub_mem()
{
    cout << "Calling Base::pub_mem()" << endl;
}