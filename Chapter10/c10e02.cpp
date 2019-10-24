#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
int main(void)
{
    list<string> slst;
    string element, word;
    cout << "Type some text: ";
    while (cin >> element)
    {
        slst.push_back(element);
    }
    cout << "Type word: ";
    cin.clear();
    fflush(stdin);
    cin >> word;
    cout << word << " occurs " << count(slst.cbegin(), slst.cend(), word)
         << " times." << endl;
    return 0;
}