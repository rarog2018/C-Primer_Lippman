#include <iostream>
using namespace std;

template <typename T, unsigned long long N>
constexpr unsigned long long size_template(T (&arr)[N])
{
    return N;
}

int main(void)
{
    int arr1[] = {0, 2, 3, 6, 9, 11, 13, 14, 21};
    char arr2[] = {'a', 'c', 'd', 'f'};

    cout << size_template(arr1) << endl;
    cout << size_template(arr2) << endl;
    return 0;
}