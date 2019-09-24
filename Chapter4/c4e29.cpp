#include <iostream>

using namespace std;

int main(void)
{
    // x is an array of 10 elements of type int
    // p points to the first element in the array x
    int x[10]; int *p = x;
    // it should print the number of elements in the array
    // because sizeof(x) gets us size of the entire array
    // in bytes, and then we divide it by size of a single
    // element, so its like answering how many elements of
    // given size can fit in the size of array x
    cout << sizeof(x)/sizeof(*x) << endl;
    // it should print 1, because pointer points to the
    // first element which has size 'n' and then we divide it
    // by 'n'
    cout << sizeof(p)/sizeof(*p) << endl;
}
