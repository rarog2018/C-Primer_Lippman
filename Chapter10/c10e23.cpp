#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;
void f(int a, int b, int c);
int main(void)
{
    // the number of arguments bind takes is n + 1, where 'n' is the number of
    // callables parameters and '1' is the callables name
    auto newCallable = bind(f, 1, _1, 3);
    newCallable(7);
    return 0;
}
void f(int a, int b, int c)
{
    cout << a << b << c << endl;
}