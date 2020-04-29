#include <iostream>
using namespace std;

int main(void)
{
    int *pa = new int[10];

    // delete pa
    delete[] pa;
    return 0;
}