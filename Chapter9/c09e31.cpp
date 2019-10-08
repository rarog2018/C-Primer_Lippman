#include <iostream>
#include <forward_list>

using namespace std;
int main(void)
{
    // program from exercise won't work for list because list does not support
    // arithmetic operations on iterators
    // forward list does not support insert, it uses insert_after instead
    forward_list<int> fli = {0, 1, 2, 3, 4, 5, 4, 4, 5, 6, 7, 8, 9};
    auto iter = fli.begin(), prev = fli.before_begin();
    while (iter != fli.end())
    {
        // prev  iter  next // 1st///
        //  1     2     3
        // prev  iter  next // 2nd//
        //  1     3     4
        if (*iter % 2)
        {
            iter = fli.insert_after(iter, *iter);
            // prev vacat  iter   next    // 2nd//
            //  1   3(o)   3(d)    4
            prev = iter;
            // vacat  prev  iter  next // 2nd//
            // 3(o)   3(d)  3(d)   4
            ++iter;
            // prev  iter  next // 2nd//
            // 3(d)   4     5
        }
        else
        { // prev  iter  next // 1st//
            //  1     2     3
            iter = fli.erase_after(prev);
            // prev  iter  next // 1st//
            //  1     3     4
        }
    }
    for (const auto &e : fli)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}