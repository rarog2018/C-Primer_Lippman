#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;
// returns true if element is greater or equal to 'sz'
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
vector<int>::const_iterator first_greater(const vector<int> &v, const string &s);
int main(void)
{
    string s = "helloes";
    const vector<int> ivec{0, 2, 4, 6, 8, 10, 12};
    cout << *first_greater(ivec, s) << endl;
    return 0;
}
// returns an iterator to the first element in vector 'v' greater than the
// size of string 's'
vector<int>::const_iterator first_greater(const vector<int> &v, const string &s)
{
    // the values in the vector (0, 2, 4) etc are being passed to placeholder _1
    // and compared to s.size() when s.size() is not greater than the placeholder
    // the check_size() returns true and that iteratr is returned by find_if_not
    const auto it = find_if_not(v.begin(), v.end(), bind(check_size, s, _1));
    return it;
}