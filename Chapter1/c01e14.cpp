#include <iostream>
using namespace std;
int main(void)
{
    // while loop is very useful when you do not know hom many iterations
    // there will be, but (like in the example below) we have to use some vari-
    // able in condition we have to declare it before the loop starts
    int val = 10;
    while (val >= 0)
    {
        cout << val-- << endl; // this line is less friendly to read with '--'
    }

    // the same loop but using for:
    // we do not have to declare val before the loop also, we do not have to
    // worry about incrementing/decrementing it in the code block,
    for (int val = 10; val >= 0; --val)
    {
        cout << val << endl;
    }
    // for loops are easier to use when we know how the number of iterations
    // that we need to do, like in our example for loop is just more readable
    return 0;
}