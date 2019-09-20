#include <iostream>

using namespace std;

int main (void)
{
    int a = 5, b = 19, c = 11;
    // in the logical 'and' operator first we evaluate left operand before
    // right operand and if its value is False then the whole expression is
    // False so the right operand does not get evaluated
    // We see it in condition below: a is not greater than c, so right hand
    // operand which value is true does not matter
    if ((a > c) && (b > c))
        cout << "A is greater than c and b is greater than c." << endl;
    // similarly in the logical 'or' operator we first evaluate left operand
    // and evaluate right operand only if the left operand is false
    // We see it in condition below: a is not greater than c, but right hand
    // operands value is true so we execute the code
    else if ((a > c) || (b > c))
        cout << "Either a or b are greater than c." << endl;
    else
        cout << "Default" << endl;
    // in the equality '==' operator we evaluate values of a and b and
    // compare them
    if (a == b)
        cout << "a is equal to b" << endl;
    else
        cout << "a is not equal to b" << endl;
}
