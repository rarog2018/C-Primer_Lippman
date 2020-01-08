#include <iostream>

using namespace std;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    int *pbeg = begin(arr), *pend = end(arr);
    for(; pbeg != pend; pbeg++)
        *pbeg = 0;
    for(pbeg = begin(arr); pbeg != pend; pbeg++)
        cout << *pbeg << " ";
    return 0;
}
