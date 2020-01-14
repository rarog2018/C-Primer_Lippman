#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
void elimDups(list<string> &words);
void print_slst(list<string> &lst);
int main(void)
{
    list<string> sentence;
    string word;
    cout << "Type a sentence: ";
    while (cin >> word)
    {
        sentence.push_back(word);
    }
    elimDups(sentence);
    return 0;
}
void elimDups(list<string> &words)
{
    cout << "Sentence before sorting:  ";
    print_slst(words);
    // sort list
    words.sort();
    cout << "Sentence after sorting:   ";
    print_slst(words);
    // unique does the job
    words.unique();
    cout << "Sentence after eraseDups: ";
    print_slst(words);
}
void print_slst(list<string> &lst)
{
    for (const auto &e : lst)
    {
        cout << e << " ";
    }
    cout << endl;
}