#include <iostream>

using namespace std;
void swap(int *a, int *b);
int main(void)
{
    int a = 5, b = 17;
    int *pa = &a, *pb = &b;
    cout << "Before swap: a = " << a << " b = " << b << endl;
    swap(pa, pb);
    cout << "After swap: a = " << a << " b = " << b << endl;

    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}