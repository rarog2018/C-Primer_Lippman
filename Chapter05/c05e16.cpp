#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int i;
    vector<int> ivec;
    cout << "Ivec: ";
    // idiomatic use
    while (cin >> i)
    {
        ivec.push_back(i);
    }
    for (decltype(ivec.size()) i = 0, sz = ivec.size(); i != sz; ++i)
    {
        cout << ivec[i] << " ";
    }

    // reset cin
    cin.clear();
    fflush(stdin);
    cout << "\nIvec2: ";
    // the other way around
    vector<int> ivec2;
    for (; cin >> i;)
    {
        ivec2.push_back(i);
    }
    decltype(ivec2.size()) j = 0, sz = ivec2.size();
    while (j != sz)
    {
        cout << ivec2[j] << " ";
        ++j;
    }
    cout << endl;
    return 0;
}