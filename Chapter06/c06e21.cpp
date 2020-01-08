#include <iostream>

using namespace std;
int larger_int(int n, int *p);
int main(void)
{
    int a = 17;
    int *p = &a;
    cout << larger_int(12, p) << endl;
    cout << larger_int(19, p) << endl;

    return 0;
}
int larger_int(int n, int *p)
{
    return (n > *p) ? n : *p;
}