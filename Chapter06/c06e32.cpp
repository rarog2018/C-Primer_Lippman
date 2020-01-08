#include <iostream>

using namespace std;
// function is legal, it takes a pointer to the first element in an array and
// an int value as parameters and returns a reference to a specific element in
// an array of ints
int &get(int *arry, int index) { return arry[index]; }
int main(void)
{
    // array of 10 elements of type int, at the moment they have garbage values
    int ia[10];
    // get returns an lvalue - reference to each element in the array
    // each element is assigned a value that corresponds to its index number
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    // proof that the code above worked
    for (const auto &e : ia)
    {
        cout << e << " ";
    }
    return 0;
}