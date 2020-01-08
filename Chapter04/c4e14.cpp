#include <iostream>

using namespace std;

int main(void)
{
    int i = 2;
    // this condition will produce an error
    // error: lvalue required as left operand of assignment
    // 42 is an rvalue, so we can't assign to it
    // if (42 = i)

    // this condition will always evaluate as true because
    // we are assigning 42 which is a nonzero value to i,
    // if we run this in a while loop it will be an infinite loop
    if (i = 42)
        cout << "True" << endl;
}
