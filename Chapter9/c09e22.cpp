#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int some_val = 1523;
    vector<int> iv{1523, 0, 1523, 1523, 325, 2, 32, 34, 27, 13};
    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + iv.size() / 2;
    size_t ivs = 0;
    // this is an infinite loop, iter is not moved to any other element
    /* while(iter != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);*/
    // this is pretty problematic because insert makes our iterators invalid
    // the question is: do we want the original mid or do we want to set new
    // mid each time when new value is inserted?
    while (iter != mid)
    {
        if (*iter == some_val)
        {
            // validate the iterator
            iter = iv.insert(iter, 2 * some_val);
            // we have to get past this place, because we will be stuck here
            // forever otherwise
            ++iter;
            // im going with the original mid,
            ++ivs;
            mid = iv.begin() + (iv.size() + ivs) / 2;
        }
        ++iter;
    }

    for (const auto &elem : iv)
        cout << elem << " ";
    cout << endl;
    return 0;
}