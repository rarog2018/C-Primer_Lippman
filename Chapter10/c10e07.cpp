#include <iostream>
#include <vector>
#include <list>

using namespace std;
void print_ivec(vector<int> &vec);
void print_ilst(list<int> &lst);
int main(void)
{
    ///////////////////////     a       ///////////////////////
    // this program is in an error, it will compile but we will get runtime
    // error: segmentation fault, because we are trying to copy elements to
    // an empty vector
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    // copy(lst.cbegin(), lst.cend(), vec.begin()); the line that causes error
    copy(lst.cbegin(), lst.cend(), back_inserter(vec)); // back_inserter performs
    // push_back operation on 'vec'
    // vec.resize(lst.size()) or we can resize the container

    print_ilst(lst);
    print_ivec(vec);

    ///////////////////////     b       ///////////////////////
    // this program is also in error: reserve only allocates contigous memory
    // that we can use it does not change the size of the vector, so the size
    // is still 0 when the fill_n function is called
    vector<int> vec1;
    vec1.reserve(10);
    // fill_n(vec1.begin(), 10, 0);
    fill_n(back_inserter(vec1), 10, 0); // again back_inserter for the rescue
    // we can also use resize()

    print_ivec(vec1);
    return 0;
}
void print_ivec(vector<int> &vec)
{
    cout << "Vector: ";
    for (const auto &e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}
void print_ilst(list<int> &lst)
{
    cout << "List: ";
    for (const auto &e : lst)
    {
        cout << e << " ";
    }
    cout << endl;
}