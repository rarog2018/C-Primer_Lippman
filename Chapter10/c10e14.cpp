#include <iostream>

using namespace std;
int main(void)
{
    // sum is a callable object that takes two int parameters and returns sum
    auto sum = [](int a, int b) { return a + b; };

    int x = 5, y = 2;
    cout << "x + y = " << sum(x, y) << endl;
    return 0;
}