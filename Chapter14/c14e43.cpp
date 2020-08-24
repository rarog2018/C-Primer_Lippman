#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main(void)
{
    vector<int> ivec{2, 3, 5, 7};
    vector<int> ivec2{15, 355, 788, 1014, 1410, 1655, 1656, 1772, 966, 1010, 49, 13};

    for (auto &i : ivec2)
    {
        int n = i;
        // prepare callable that will bind the modulus: n % _1
        auto newModulus = bind(modulus<int>(), n, _1);

        auto it = find_if_not(ivec.begin(), ivec.end(), newModulus);

        if (it != ivec.end())
        {
            cout << n << " is divisible by " << *it << endl;
        }
        else
        {
            cout << n << " is not divisible by any of the numbers from the list" << endl;
        }
    }

    return 0;
}