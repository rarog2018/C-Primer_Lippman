#include <iostream>

using namespace std;

int main(void)
{
    int result;
    int someValue = 1, x = 7, y = 19;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << endl;

    // first we have to remember that the result of
    // comma operator is the value of its right
    // side expression,
    // int this case ++x, ++y the result is  ++y
    // which we can see in the print below
    result = someValue ? ++x, ++y : --x, --y;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << " result = "
        << result << endl;

    // why then the value of y did not increment?
    // its because of the precedence of comma operator
    // which is the lowest in c++
    // we are getting the result of (++x, ++y) as
    // a one expression only because it is between
    // '?' and ':' which has higher precedence than
    // the comma operator
    // it is not the case for second expression
    // so --x, --y is not (--x, --y), so the result
    // is --x, which we can see in the print below

    // this means that --y is executed always
    // (someValue ? ++x, ++y : --x), --y
    // when someValue is positive the result is ++y
    // when someValue is negative the result is --x

    someValue = 0;
    result = someValue ? ++x, ++y : --x, --y;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << " result = "
        << result << endl;

    // Proof that with the parenthesis that i wrote
    // above the results are exactly the same
    cout << "\nProof that with parenthesis results are the same:\n";

    someValue = 1, x = 7, y = 19;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << endl;

    result = (someValue ? ++x, ++y : --x), --y;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << " result = "
        << result << endl;

    someValue = 0;
    result = (someValue ? ++x, ++y : --x), --y;
    cout << "someValue = " << someValue << " x = "
        << x << " y = " << y << " result = "
        << result << endl;
}
