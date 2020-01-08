#include <iostream>
#include <forward_list>

using namespace std;
int main(void)
{
    forward_list<int> flst{0, 1, 1, 2, 3, 17, 21, 22, 87, 90};

    // denotes element one before the beginning of the list
    for (auto prev = flst.before_begin(), curr = flst.begin();
         curr != flst.end();)
    {
        if (*curr % 2)
        {
            // if curr is odd erase after previous element (which is the elem
            // that curr currently denotes), function returns an iterator to
            // the element after the one deleted, and we assign it to curr
            curr = flst.erase_after(prev);
            // prev curr erase_after next
            //  2    3      17        21

            // prev curr   next
            //  2    17     21
        }
        else
        { //   prev curr next
            //   1   2    3
            prev = curr;
            // prev curr  next
            //   2   2     3
            ++curr;
            // prev curr next
            //   2   3    17
        }
    }

    for (const auto &e : flst)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}