#include <iostream>

using namespace std;

int main(void)
{
    constexpr int size = 5;
    int ia[size] = {1,2,3,4,5};

    // ptr is a pointer to int assigned to first
    // element in array ia, ix is an int of value 0
    for (int *ptr = ia, ix = 0;
    // until ix is different than constexpr int size
    // AND until ptr is different than ia + size
    // (which will get us one past the last element
    // in array ia)
    // both conditions have to be true or we exit
    ix != size && ptr != ia+size;
    // first evaluate ++ix, then ++ptr
    // ++ix increments the value of ix
    // ++ptr makes ptr point to the next element
    ++ix, ++ptr)
        cout << "ix = " << ix << ", *ptr = " << *ptr << endl;
}
