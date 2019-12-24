#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void print_vec(const vector<int> v);
int main(void)
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec2, ivec3;
    list<int> ilst4;

    // the result will be the same as original vector
    copy(ivec.cbegin(), ivec.cend(), inserter(ivec2, ivec2.begin()));
    cout << "ivec2: ";
    print_vec(ivec2);

    // the result will be the same as original vector
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec3));
    cout << "\nivec3: ";
    print_vec(ivec3);

    // the result will be reversed to the original vector
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst4));
    cout << "\nilst4: ";
    for (auto &e : ilst4)
    {
        cout << e << " ";
    }
    return 0;
}
void print_vec(const vector<int> v)
{
    for (auto &e : v)
    {
        cout << e << " ";
    }
}