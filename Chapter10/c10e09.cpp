#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void elimDups(vector<string> &words);
void print_svec(vector<string> &vec);
int main(void)
{
    vector<string> sentence;
    string word;
    cout << "Type a sentence: ";
    while (cin >> word)
    {
        sentence.push_back(word);
    }
    elimDups(sentence);
    return 0;
}
void elimDups(vector<string> &words)
{
    cout << "Sentence before sorting:  ";
    print_svec(words);
    // sort vector
    sort(words.begin(), words.end());
    cout << "Sentence after sorting:   ";
    print_svec(words);
    // erase elements denoted by range determined by unique algorithm and
    // end iterator
    words.erase(unique(words.begin(), words.end()), words.end());
    cout << "Sentence after eraseDups: ";
    print_svec(words);
}
void print_svec(vector<string> &vec)
{
    for (const auto &e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}