#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void)
{
    // initialize list with 8 elements "Hi"
    list<const char *> chlist(8, "Hi");
    vector<string> svec;
    // assign whole list to svec
    svec.assign(chlist.cbegin(), chlist.cend());

    for(const auto &e : svec)
        cout << e << " ";
    cout << endl;
}
