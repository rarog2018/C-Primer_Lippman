#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main(void)
{
    int pos = 0; // because crend() is not firts but one before first
    list<int> ilst{0, 1, 5, 7, 0, 2, 7};
    // set beg to one before the first element in the list
    list<int>::const_reverse_iterator beg = ilst.crend();
    // find the last element with value 0 in the list and store its position
    // in the rit iterator
    list<int>::const_reverse_iterator rit = find(ilst.crbegin(), ilst.crend(), 0);

    // elements in the list are not contiguous so we cannot use arithmetic
    // operation to determine the position, rather we need to calculate it
    // going from the first element up until 'rit'
    while (beg != rit)
    {
        ++pos;
        --beg;
    }
    cout << "The last element with value 0 in the list is at position: "
         << pos << endl;
    return 0;
}