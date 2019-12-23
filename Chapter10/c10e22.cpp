#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;
void elimDups(vector<string> &words);
void print_svec(vector<string> &vec);
void biggies(vector<string> &words, vector<string>::size_type sz);
bool isShorter(const string &a, const string &b);
bool hasSix(const string &a, int x);
void printWord(const string &a);
int main(void)
{
    vector<string> sentence;
    string word;
    vector<string>::size_type n;

    cout << "Type a sentence: ";
    while (cin >> word)
    {
        sentence.push_back(word);
    }
    biggies(sentence, 6);
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // sorts words in alphabetical order and eliminate duplicates
    elimDups(words);

    // sort words by size and maintain alphabetical order
    stable_sort(words.begin(), words.end(), isShorter);
    cout << "Sentence after stable_sort: ";
    print_svec(words);

    // get iterator to the first element which size is >= sz
    // auto has6 = bind(hasSix, _1, 4);
    auto it = find_if(words.begin(), words.end(), bind(hasSix, _1, sz));

    // calculate the number of elements that are >= sz using count_if
    auto numOfEl = count_if(words.begin(), words.end(), bind(hasSix, _1, sz));
    cout << "Number of elements greater than or equal to " << sz << ": " << numOfEl << endl;

    // print elements that are >= sz
    for_each(it, words.end(), printWord);
}
// eliminates duplicate words from vector
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
// prints the contents of vector<string>
void print_svec(vector<string> &vec)
{
    for (const auto &e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}
// checks if element a is smaller than b
bool isShorter(const string &a, const string &b)
{
    return a.size() < b.size();
}
// checks if 'a' is greater than or equal to 'x'
bool hasSix(const string &a, int x)
{
    return a.size() >= x;
}
// prints 'a'
void printWord(const string &a)
{
    cout << a << " ";
}