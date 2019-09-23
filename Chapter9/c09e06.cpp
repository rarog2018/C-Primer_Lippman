#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> lst1{1};
    list<int>::iterator iter1 = lst1.begin(),
    iter2 = lst1.end();
    // list iterators do not support iterator arithmetic
    // its because lists elements are not contiguous in
    // memory, instead each element links to another's
    // address, which may be wherever in memory, so
    // comparing these addresses makes no sense
    //while (iter1 < iter2)
    // but we can check if the iterators point to the
    // same place in memory and also increment them
    // to another element
    while (iter1 != iter2)
    {
        cout << "iter1 < iter2" << endl;
        ++iter1;
    }
}
