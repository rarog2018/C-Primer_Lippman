#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
    // iterators bound to standart input, output
    istream_iterator<int> iii(cin), eof;
    ostream_iterator<int> ioi(cout, " ");
    // vector initialized from the istream_iterators
    vector<int> ivec(iii, eof);
    // sort vector
    sort(ivec.begin(), ivec.end());
    // print sorted, unique contents of the vector
    unique_copy(ivec.cbegin(), ivec.cend(), ioi);
    return 0;
}