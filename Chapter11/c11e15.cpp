#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int main(void)
{
    map<int, vector<int>>::mapped_type v1; // v1 is a vector of ints
    map<int, vector<int>>::key_type v2;    // v2 is an int

    // proof
    for (int i = 0; i < 3; ++i)
    {
        v1.push_back(i * 8);
    }
    v2 = 17;

    map<int, vector<int>>::value_type v3{v2, v1}; // v3 is a pair<const int, vector<int>>

    cout << "Third element of the vector v1: " << v1[2] << endl;
    cout << "Int v2 yields " << v2 << endl;
    // v3.first = 15; // error: assignment of read-only member,
    cout << "v3.first: " << v3.first << ", v3.second[2]: " << v3.second[2] << endl;
    return 0;
}