#include <iostream>

using namespace std;
// parameters are local variables declared inside the function parameter list
// int a and int b are parameters of function add_num
void add_num(int a, int b);
void ref_add_num(int &x, int &y);
int main(void)
{
    int a = 2, b = 5;
    cout << "Before function call: a = " << a << " b = " << b << endl;
    // arguments are the initializers for a function's parameters
    // a and b are the arguments of add_num function
    add_num(a, b);
    // we can see that even though we added a value to 'a' inside the function
    // it didn't change the 'a' outside of the function, thus we can indeed
    // see that parameters are local variables and even though they have the
    // same names and types variable 'a' from parameter list and variable 'a'
    // from main block are different variables
    cout << "After function call: a = " << a << " b = " << b << endl;

    // by passing a reference to an object we can achieve what we wanted and
    // change the value of the 'real a'
    ref_add_num(a, b);
    cout << "After function2 call: a = " << a << " b = " << b << endl;

    return 0;
}

void add_num(int a, int b)
{
    a = a + b;
    cout << "Inside function call: a = " << a << " b = " << b << endl;
}

void ref_add_num(int &x, int &y)
{
    x = x + y;
    cout << "\nInside function2 call: a = " << x << " b = " << y << endl;
}