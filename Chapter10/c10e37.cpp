#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int main(void)
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilst(7 - 2);
    // index 2 is position 3
    copy(ivec.begin() + 2, ivec.begin() + 7, ilst.rbegin());
    for (const auto &e : ilst)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}