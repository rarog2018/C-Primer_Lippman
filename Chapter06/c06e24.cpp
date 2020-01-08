#include <iostream>

using namespace std;
// function takes a pointer to an array as a parameter, which is problematic,
// because inside the function for loop assumes that there is 10 elements in
// the array, but we can pass an array of size different than 10, which may
// lead to an error
// void print(const int ia[10])
// to fix this we have to properly pass a reference to an array of 10 ints
void print(const int (&ia)[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
int main(void)
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[5] = {5, 6, 7, 8, 9};
    print(arr);
    // print(arr2); with first version of this function this may cause runtime
    // error, while with second version of this function the program will not
    // compile, because the argument does not match parameter list
    return 0;
}
