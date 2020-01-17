#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    multiset<string> c = {"the", "but", "and", "or", "or",
                          "an", "a",
                          "The", "But", "And", "Or", "An", "An",
                          "A"};
    vector<string> v{"hello", "world", "light", "bright", "Seven"};

    ////////////////////////            a           ////////////////////////
    // it is legal, copies the elements from the input range which is all
    // elements in a vector of strings into destination which is a multiset of
    // strings
    // each element is inserted in alphabetic order (uppercase first)
    copy(v.begin(), v.end(), inserter(c, c.end()));
    for (const auto &e : c)
    {
        cout << e << " ";
    }
    cout << endl;

    ////////////////////////            b           ////////////////////////
    // it is illegal, because multiset does not have a push_back member, so
    // back_inserter can't work
    // keys in multiset have to be in ascending order
    // copy(v.begin(), v.end(), back_inserter(c));

    ////////////////////////            c           ////////////////////////
    // it is legal, copies all the keys from the multiset into vector ahead
    // of the element denoted by v.end() argument
    copy(c.begin(), c.end(), inserter(v, v.end()));
    for (const auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    ////////////////////////            d           ////////////////////////
    // it is legal, vector has a push_back member, copies every key from the
    // multiset into vector (each element is added at the end)
    copy(c.begin(), c.end(), back_inserter(v));
    for (const auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    // because of the argument used in the call to inserter(), c) and d) are
    // equivalent
    return 0;
}