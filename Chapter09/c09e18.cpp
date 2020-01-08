#include <iostream>
#include <deque>
#include <string>

using namespace std;
int main(void)
{
    string word;
    deque<string> dqs;
    // write elements to the deque
    while (cin >> word)
    {
        dqs.push_back(word);
    }

    // print the elements
    for (auto it = dqs.cbegin(), fin = dqs.cend(); it != fin; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}