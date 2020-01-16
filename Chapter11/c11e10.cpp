#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    // it is possible to create a map from vector<int>::iterator to int, because
    // vector<int>::iterator is a random-access iterator, and it supports the
    // relational operators including '<' which is required for the key_type
    // of a map

    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7};
    vector<int>::iterator it(ivec.begin());
    map<vector<int>::iterator, int> iitvimap;
    iitvimap = {{it, 7}, {it + 1, 11}};
    iitvimap[it + 2] = 82;
    iitvimap[it] = 14;

    for (auto &e : iitvimap)
    {
        cout << *(e.first) << " " << e.second << endl;
    }

    // it is not possible to create a map from list<int>::iterator to int,
    // because list<int>::iterator is a bidirectional iterator, which does not
    // support relational operators, so it does not meet the requirements for
    // the key_type, hence it can't be a key_type

    // compilator will generate error
    // error: no match for 'operator<' (operand types are
    // 'const std::_List_iterator<int>' and 'const std::_List_iterator<int>'
    /*list<int> ilst{0, 1, 2, 3, 4, 5, 6, 7};
    list<int>::iterator itl(ilst.begin());
    map<list<int>::iterator, int> iitlstimap;
    iitlstimap = {{itl, 7}};

    for (auto &e : iitlstimap)
    {
        cout << *(e.first) << " " << e.second << endl;
    }
    */
    return 0;
}