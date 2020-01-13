#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main(void)
{
    /*
    List has bidirectional iterators.
    Vector has random-access iterators.
    */

    list<int> ilst{0, 1, 2, 3, 5};
    // cout << ilst[2] << endl; // error: no match for 'operator[]', list does
    // not have random-access iterators
    list<int>::const_reverse_iterator it = ilst.crbegin(); // ok list has
    // bidirectional iterators so we can traverse it backward
    for (; it != ilst.crend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> ivec{0, 1, 2, 3, 5};
    cout << ivec[2] << endl; // ok vector has random-access iterators
    return 0;
}