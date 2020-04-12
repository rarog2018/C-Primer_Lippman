#include <iostream>
using namespace std;

struct X
{
    // 'rem' is initialized first, because it is declared before 'base'
    // there are couple of ways to fix this f.e.
    // - change int rem, base; to int base, rem;
    // - use parameters to initialize rem (better option)
    // X(int i, int j) : base(i), rem(base % j) {}
    X(int i, int j) : base(i), rem(i % j) {}
    int rem, base;
    // int base, rem;
};

int main(void)
{
    X obj(5, 7);
    cout << obj.base << " " << obj.rem << endl;
    return 0;
}