#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool has_five(const string &s1);
int main(void)
{
    vector<string> words;
    string word;
    cout << "Write a sentence: ";
    while (cin >> word)
    {
        words.push_back(word);
    }
    // 'part' is an iterator that points to one past the last element for which
    // the predicate returned true
    vector<string>::iterator part = partition(words.begin(), words.end(), has_five);
    // loop from the beginning of the vector to the last element for which the
    // predicate returned true
    for (vector<string>::const_iterator it = words.cbegin(); it != part; ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
// return true if string has 5 or more characters
bool has_five(const string &s1)
{
    return (s1.size() >= 5) ? true : false;
}