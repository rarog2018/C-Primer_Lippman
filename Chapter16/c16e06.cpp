#include <iostream>
using namespace std;

// T is the type of the elements in array and N is the size of the array
template <typename T, unsigned long long N>
constexpr T *begin_template(T (&arr)[N])
{
    return arr;
}

template <typename T, unsigned long long N>
constexpr T *end_template(T (&arr)[N])
{
    return &arr[N]; // return the address of the last element
}

int main(void)
{
    int arr1[] = {0, 2, 3, 6, 9, 11, 13, 14, 21};

    cout << "Library version: " << begin(arr1) << ", " << end(arr1) << endl;
    cout << "Template version: " << begin_template(arr1) << ", " << end_template(arr1) << endl;

    auto it = end(arr1);
    --it;
    cout << *it << endl;
    auto it2 = end_template(arr1);
    --it2;
    cout << *it2 << endl;
    return 0;
}