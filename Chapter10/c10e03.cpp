#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(void)
{
    vector<int> ivec{1, 2, 5, 16, 99, 101, 555};
    // the third argument is 0, because it determines the type of "+" operator
    // and the returned value which should be int
    cout << "Total sum of elements in ivec equals: "
         << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
    return 0;
}