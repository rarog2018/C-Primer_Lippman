#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
int main(void)
{
    vector<int> ivec{1, 3, 5, 5, 7, 9, 11, 11, 13, 15};
    list<int> ilst;

    cout << "ivec has " << ivec.size() << " elements: ";
    for (auto &e : ivec)
    {
        cout << e << " ";
    }

    // copy only unique elements
    unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
    cout << "\nilst has " << ilst.size() << " elements: ";
    for (auto &e : ilst)
    {
        cout << e << " ";
    }
    return 0;
}