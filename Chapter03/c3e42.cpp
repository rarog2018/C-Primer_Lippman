#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    constexpr size_t ars = 10;
    int arr[ars];
    int *pbeg = begin(arr), *pend = end(arr);
    for(auto it = v.cbegin(); it != v.cend() && pbeg != pend; it++, pbeg++)
        *pbeg = *it;
    for(const auto e : arr)
        cout << e << " ";
    return 0;
}
