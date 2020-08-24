#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main(void)
{
    //////////////////////////////////////////////////////////////////////////
    // a) Count the number of values that are greater than 1024
    vector<int> ivec{15, 355, 788, 1014, 1410, 1655, 1656, 1772, 966, 1010};

    // use bind to bind the value 1024 to the callable
    auto newGreater = bind(greater<int>(), _1, 1024);
    // use count_if algorithm to count the number of values that pass the test
    cout << "There are " << count_if(ivec.begin(), ivec.end(), newGreater)
         << " values greater than 1024 in the sequence" << endl;
    ///////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // b) Find the first string that is not equal to pooh
    vector<string> svec{"pooh", "pooh", "winnie", "the", "pooh"};

    // use bind to bind the value "pooh" to the callable
    auto newNotEqualTo = bind(not_equal_to<string>(), _1, "pooh");

    cout << "The first string that is not equal to 'pooh' is "
         << *find_if(svec.begin(), svec.end(), newNotEqualTo) << endl;
    ///////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // c) Multiply all values by 2
    // use bind to bind the value 2 to the callable
    auto newMultiplies = bind(multiplies<int>(), _1, 2);

    // apply the callable to each element
    transform(ivec.begin(), ivec.end(), ivec.begin(), newMultiplies);

    for (auto &i : ivec)
        cout << i << " ";
    cout << endl;
    //////////////////////////////////////////////////////////////////////////
    return 0;
}