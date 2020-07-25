#include <iostream>
#include <vector>
using namespace std;

int f() { return 7; }
int f2()
{
    int a = 7;
    cout << "Address of a: " << &a << endl;
    return a;
}
int main(void)
{
    vector<int> vi(100);

    int &&rr1 = f(); // rvalue reference, even if the value 7 was bound to
    // a variable defined in the f(), that variable would be local, hence it
    // would be destroyed when the function terminates, so we can "catch" it
    int &&rr1a = f2();
    cout << "Address of rr1a: " << &rr1a << endl;

    // exercise
    int &&r1 = f();  // rvalue reference as above
    int &r2 = vi[0]; // lvalue reference, because the subscribt operator
    // returns an lvalue: *vi
    int &r3 = r1;           // lvalue reference, because variable r1 is an lvalue
    int &&r4 = vi[0] * f(); // rvalue reference, because the expression's
    // result is a temporary object (an rvalue)
    return 0;
}