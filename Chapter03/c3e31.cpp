#include <iostream>

using namespace std;

int main()
{
    constexpr size_t arr_size = 10;
    int arr[arr_size];
    for(size_t i = 0; i < arr_size; i++)
        arr[i] = i;
    for(auto el : arr)
        cout << arr[el] << " ";

    return 0;
}
