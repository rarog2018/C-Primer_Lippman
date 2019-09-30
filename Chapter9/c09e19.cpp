#include <iostream>
// 1. changed include from deque to list
#include <list>
#include <string>

using namespace std;
int main(void)
{
    string word;
    // 2. changed container type and name
    list<string> slst;
    // write elements to the list
    while (cin >> word)
    {
        // 3. changed container name
        slst.push_back(word);
    }

    // print the elements
    // 4. changed container name, but i could have used less descriptive name
    // it was not necessary, only 2 changes were necessary
    for (auto it = slst.cbegin(), fin = slst.cend(); it != fin; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}