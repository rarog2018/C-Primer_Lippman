#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(void)
{
    list<string> slist{"Jello", "madre"};

    auto elem1 = slist.begin();
    auto elem2 = elem1;
    cout << "after initialization: elem1 = " << *elem1 << " elem2 = "
         << *elem2 << endl;
    // if elem1 and elem2 are equal nothing will be erased, because
    // elem1 is the first element to be erased and elem2 is one past the last
    // element that has to be erased, so there are no elements before
    // elem1 and elem2 to be erased
    elem1 = slist.erase(elem1, elem2);
    cout << "elem1 after erase process: " << *elem1 << endl;
    // proof
    for (const auto &elem : slist)
    {
        cout << elem << " ";
    }
    // if elem2 is off-the-end iterator then all elements between elem1 and
    // elem2 will be erased
    // if elem1 and elem2 are both off-the-end iterators nothing will happen
    elem1 = elem2 = slist.end();
    elem1 = slist.erase(elem1, elem2);
    cout << endl;

    for (const auto &elem : slist)
    {
        cout << elem << " ";
    }
}
