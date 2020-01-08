#include <iostream>

using namespace std;

int main(void)
{
    int i = 1, j = 2, k = 3;
    // relational operator has higher priority than inequality
    // so first we evaluate j < k which will give us True or False
    // aka 1 or 0, then we check for inequality between i and the
    // result of j < k
    // If the value of i is different than 0 or 1 the condition will
    // always evaluate as True. If the value of i is 0 or 1, then
    // the value of the condition depends on the result of j < k
    if (i != j < k)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
