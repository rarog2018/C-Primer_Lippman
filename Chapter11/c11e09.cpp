#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;
int main(void)
{
    list<int> lineNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string word;
    // map that has the key of type string and value of type list<int>
    map<string, list<int>> wordLines;
    // initial assignments
    wordLines["hello"] = {2, 7};
    wordLines["world"] = {1, 3};
    // adding new value to the list<int> associated with "hello"
    wordLines["hello"].push_back(9);

    for (const auto &pair : wordLines)
    {
        cout << pair.first << ": ";
        for (const auto &line : pair.second)
        {
            cout << line << " ";
        }
        cout << endl;
    }
    return 0;
}