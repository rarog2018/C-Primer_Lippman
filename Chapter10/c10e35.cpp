#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = ivec.cend() - 1; it + 1 != ivec.cbegin(); --it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}