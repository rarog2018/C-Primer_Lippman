#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// T will be the iterator type, U is the type of the value
template <typename T, typename U>
T find_template(const T &beg, const T &end, const U &val)
{
    for (auto it = beg; it != end; ++it)
    {
        if (*it == val)
            return it;
    }
    return end;
}

int main(void)
{
    vector<int> ivec{0, 15, 22, 33, 14, 17, 99};
    list<string> slst{"Witcher", "Malazan", "LOTR", "Narnia"};

    // auto i = find_template(ivec.begin(), ivec.end(), 17); // ok!
    auto i = find_template(ivec.begin(), ivec.end(), 19); // also works!

    if (i == ivec.end())
        cout << "Value not found" << endl;
    else
        cout << "Value is in the vector" << endl;

    // auto j = find_template(slst.begin(), slst.end(), "LOTR"); // ok!
    auto j = find_template(slst.begin(), slst.end(), "ASOIAF");

    if (j == slst.end())
        cout << "Value not found" << endl;
    else
        cout << "Value is in the list" << endl;
    return 0;
}