#include <iostream>

using namespace std;
int getPtr();
int main(void)
{
    int p, i;
    // without parenthesis we will first evaluate
    // getPtr() != 0 expression which will return bool
    // value and then assign it to p variable
    // with parenthesis we assign the result of getPtr()
    // function to p and then check if that value is
    // different from 0
    if ((p = getPtr()) != 0)
        cout << p << endl;

    // as in one of the previous exercises we assign
    // a nonzero value to a variable, hence this condition
    // will always evaluate as true
    // the condition should instead check for equality
    if (i == 1024)
        cout << i << endl;
}

int getPtr()
{
    return 2;
}
