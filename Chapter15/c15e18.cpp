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
    // error: private members are inaccessible to derived classes
    // char g() { return priv_mem; }
};

struct Priv_Derv : private Base
{
    // private derivation doesn't affect access in the derived class
    int f1() const { return prot_mem; }
};

struct Prot_Derv : protected Base
{
    // private derivation doesn't affect access in the derived class
    int f2() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv
{
    // ok: Base::prot_mem remains protected in Pub_Derv
    int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv
{
    // error: Base::prot_mem is private in Priv_Derv
    // int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv
{
    // ok: Base::prot_mem remains protected in Prot_Derv
    int use_base() { return prot_mem; }
};

int main(void)
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    // Well, this is legal and won't end in an error at compile time, but we
    // will have only access to the public members from the Base class
    Base *p = &d1; // d1 has type Pub_Derv
    p->pub_mem();  // this works
    // cout << *p->f() << endl;    // this won't

    // This is illegal, we cannot convert to Base class members that we don't
    // have access to. Even though d2 derived public member from the Base class
    // pub_mem(), it is now a private member of d2 object, hence we cannot access
    // it and in result cannot convert it to Base class type.
    // p = &d2;

    // Illegal, for the same reasons as above.
    // p = &d3;

    // Legal, but as in the first example wewill have access only to the public
    // members of the Base class
    p = &dd1;
    p->pub_mem();

    // Illegal for the same reasons as the examples above
    // p = &dd2;

    // Illegal, same as above
    // p = &dd3;
    return 0;
}

inline void Base::pub_mem()
{
    cout << "Calling Base::pub_mem()" << endl;
}