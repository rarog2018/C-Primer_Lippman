#include <iostream>

using namespace std;
// parameter is a kind of a local variable, it exist only while the function
// is executed, so the difference between parameters and other local variables
// is the place in which they are declared - parameters in a function declaration
// inside parameter list, other local variables inside the function block
// 'a' is a parameter
void f(int a)
{
    // 'b' is a local variable
    int b = 5;
    // 'c' is a local static object which will exist as long as program runs
    static int c = 21;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    // incrementation of both 'a' and 'b' will have no effect outside of this
    // function call, while 'c' will change its value
    ++a, ++b, ++c;
}
int main(void)
{
    int x = 7;
    f(x);
    // we can't access 'a' nor 'b' nor 'c' from here
    // cout << "a = " << a << " b = " << b << " c = " << c << endl;
    // because static variables are not destroyed after function terminates
    // the value of 'c' will be successfuly incremented, while the other two
    // variables are created and initialized again
    f(x);
    return 0;
}