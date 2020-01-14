#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    // store the words and their count in a map
    map<string, int> wordCount;
    string word;

    // read a sequence
    while (cin >> word)
    {
        // place each word as a key in the map and increment its counter
        // if the word is not in the map already the new entry will occur with
        // counter set to 0, which will be immediately incremented
        ++wordCount[word];
    }

    // print how many times each word occured
    for (const auto &e : wordCount)
    {
        cout << e.first << " occured " << e.second << " times" << endl;
    }
    return 0;
}