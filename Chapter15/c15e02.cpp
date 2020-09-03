#include <iostream>
using namespace std;

// members inside the scope of the 'protected' access specifier can be accessed
// by the derived class objects, while those within 'private' cannot

class BaseClassN
{
public:
    virtual void member1();

protected:
    int protNum = 13;

private:
    int privNum = 17;
};

class DerivedClassN : public BaseClassN
{
public:
    void member1() { cout << "Overriding member1 from the base class" << endl; }
    // we can access the protected member
    void printer() { cout << protNum << endl; }
    // but we cannot access the private member
    // void printer2() { cout << privNum << endl;} // error
};

int main(void)
{
    DerivedClassN obj;
    obj.printer();
    return 0;
}