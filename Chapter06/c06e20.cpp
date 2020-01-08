#include <iostream>

using namespace std;
// the answer is pretty much in exercise 16 with examples, but as a summary
// reference parameters should be references to const every time we do not want
// to change the object
// if we make a parameter a plain reference it cannot take const object,
// a literal (like "hello" or 3.14), an object that has to be converted or an
// expression that can be evaluated to the parameters type

void example(int &d)
{
    cout << d << endl;
}

void example2(const int &d)
{
    cout << d << endl;
}
int main(void)
{
    int a = 7;
    double pi = 3.14;
    example(a);
    // we cannot pass 'pi' to this function because conversion can't happen
    // example(pi);
    // we cannot pass 'a + pi' expression to this function even if it can be
    // evaluated to an int
    // example(a + pi);

    // but we can pass 'pi' to the same function that takes a reference to const
    // as a parameter, then the conversion from double to int will happen
    example2(pi);
    // we can pass an expression that will evaluate to int
    example2(a + pi);
    // off course our 'pi' object was not changed, it was just printed as an int
    cout << pi << endl;
    return 0;
}