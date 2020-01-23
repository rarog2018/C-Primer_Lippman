#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    map<string, vector<int>> sivecmap{{"hello", {5, 14, 22}}, {"martha", {1}}};

    auto lbit = sivecmap.lower_bound("aorld");
    auto lbit2 = sivecmap.lower_bound("world");

    if (lbit2 == sivecmap.end() && lbit == sivecmap.begin())
    {
        cout << "lower_bound returns the iterator to the first element with the"
                " key not less than the given key."
             << endl;
    }

    auto ubit = sivecmap.upper_bound("aorld");
    auto ubit2 = sivecmap.upper_bound("world");
    if (ubit == sivecmap.begin() && ubit2 == sivecmap.end())
    {
        cout << "upper_bound returns the iterator to the first element with the"
                " key greater than the given key."
             << endl;
    }

    auto erits = sivecmap.equal_range("world");
    if (erits.first == sivecmap.end() && erits.second == sivecmap.end())
    {
        cout << "equal_range returns a pair of iterators, which if key is not"
                " present, both will be the off-the-end iterator."
             << endl;
    }
    return 0;
}