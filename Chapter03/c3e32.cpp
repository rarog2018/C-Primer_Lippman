#include <iostream>
#include <vector>
using namespace std;
constexpr size_t arr_size = 10;

void fill_array(int a[], size_t ars);
void copy_array(const int a[], int b[], size_t ars);
void print_array(const int a[], size_t ars);

int main()
{

    int arr[arr_size];
    fill_array(arr, arr_size);
    cout << "Array 1: ";
    print_array(arr, arr_size);
    size_t arr2_size = sizeof(arr) / sizeof(int);
    int arr2[arr2_size];
    cout << endl;
    copy_array(arr, arr2, arr2_size);
    cout << "Array 2: ";
    print_array(arr2, arr2_size);

    //////////vectors/////////////////////////
    cout << endl;
    vector<int> v1;
    for(size_t i = 0; i != 10; i++)
        v1.push_back(i);

    vector<int> v2(v1);
    cout << "Vector 2: ";
    for(auto el : v2)
        cout << el << " ";
    return 0;
}

void fill_array(int a[], size_t ars)
{
    for(size_t i = 0; i < ars; i++)
        a[i] = i;
}

void copy_array(const int a[], int b[], size_t ars)
{
    for(size_t i = 0; i < ars; i++)
    {
        b[i] = a[i];
    }
}

void print_array(const int a[], size_t ars)
{
    for(size_t i = 0; i < ars; i++)
        cout << a[i] << " ";
}
