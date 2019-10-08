#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();

    while (begin != v.end())
    {
        cout << *begin << " ";
        ++begin;
        // this will invalidate the begin iterator
        // exited with code=3221226356 in my case
        // ivalid iterator behaves in an undefined way
        //  v.insert(begin, 42);
        begin = v.insert(begin, 42); // iterator has to be validatet
        ++begin;
    }
    cout << endl;
    return 0;
}