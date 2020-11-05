#include <iostream>
using namespace std;

// Original function
void print(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}

// template version
template <typename T, size_t N>
void print_template(const T (&arr)[N])
{
    for (auto elem : arr)
        cout << elem << endl;
}

int main(void)
{
    const int arr1[6] = {0, 2, 4, 7, 8, 11};
    print_template(arr1);

    return 0;
}