#include <iostream>

using namespace std;
void print_sum(int a);
int main(void)
{
    print_sum(7);
    return 0;
}
void print_sum(int a)
{
    // sumLambda is a callable object that captures 'a' variable from function
    // print_sum parameter list, takes one int argument and returns the sum of them
    auto sumLambda = [a](int b) { return a + b; };
    int x = 11;
    cout << a << " + " << x << " = " << sumLambda(x) << endl;
}