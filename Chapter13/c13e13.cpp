#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X
{
    // constructor
    X() : i(0) { cout << "X()" << endl; }
    // copy constructor
    X(const X &) { cout << "X(const X&)" << endl; }
    // copy-assignment operator
    X &operator=(const X &);
    // destructor
    ~X() { cout << "~X()" << endl; }

    int i;
};

//
X &X::operator=(const X &rhs)
{
    cout << "X &operator=" << endl;
    i = rhs.i;
    return *this;
}

// reference
void randomFnc(const X &ob)
{
    cout << ob.i << endl;
}
// nonreference
void randomFnc2(const X ob)
{
    cout << ob.i << endl;
}
int main(void)
{
    X first;
    X second(first);
    X third = second; // here my compiler omits the assignment operator
    third = first;

    randomFnc(first);
    randomFnc2(second); // uses copy constructor to create temp parameter object

    vector<X *> abc{&first, &second, &third};
    vector<X> cde{first, second, third};

    X *fourth = new X;
    delete fourth;
    return 0;
}