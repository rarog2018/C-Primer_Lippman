#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // initialize vector from the begining of the arr to its 5th element
    vector<int> v(begin(arr), arr + 5);
    for(auto e : v)
        cout << e << " ";
    return 0;
}
