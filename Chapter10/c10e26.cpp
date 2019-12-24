#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
void print_lst(const list<int> &l);
int main(void)
{
    list<int> lst1{1, 3, 5, 7, 9, 11, 13, 15};
    list<int> lst2, lst3{-3, -1}, lst4{-3, -1};
    cout << "lst1: ";
    print_lst(lst1);

    // front_inserter uses push_front() so each inserted element becomes the
    // new first element, as we can see after print last element in lst1 become
    // the first element of lst2,
    copy(lst1.cbegin(), lst1.cend(), front_inserter(lst2));
    cout << "lst2: ";
    print_lst(lst2);

    // inserter(c, iter) inserts each element ahead of the element originally
    // denoted by iter (in our case ++lst3.begin()), as we can see it everything
    // got placed between '-3' and '-1' which were the original two elements
    copy(lst1.cbegin(), lst1.cend(), inserter(lst3, (++lst3.begin())));
    cout << "lst3: ";
    print_lst(lst3);

    // back_inserter uses push_back so each inserted element becomes the new
    // last element, as we can see first element of lst1 became 3rd element
    // (last after two original elements) and the last element of lst1 is still
    // the last element of lst4
    copy(lst1.cbegin(), lst1.cend(), back_inserter(lst4));
    cout << "lst4: ";
    print_lst(lst4);
    return 0;
}
void print_lst(const list<int> &l)
{
    for (auto &e : l)
    {
        cout << e << " ";
    }
    cout << endl;
}