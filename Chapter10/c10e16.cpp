#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void elimDups(vector<string> &words);
void print_svec(vector<string> &vec);
void biggies(vector<string> &words, vector<string>::size_type sz);
int main(void)
{
    vector<string> sentence;
    string word;
    vector<string>::size_type n;

    cout << "Type a size: ";
    cin >> n;
    cout << "Type a sentence: ";
    while (cin >> word)
    {
        sentence.push_back(word);
    }
    biggies(sentence, n);
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // sorts words in alphabetical order and eliminate duplicates
    elimDups(words);

    // sort words by size and maintain alphabetical order
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    cout << "Sentence after stable_sort: ";
    print_svec(words);

    // get iterator to the first element which size is >= sz
    auto it = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });

    // calculate the number of elements that are >= sz
    auto numOfEl = words.end() - it;
    cout << "Number of elements greater or equal to " << sz << ": " << numOfEl << endl;

    // print elements that are >= sz
    for_each(it, words.end(), [](const string &a) { cout << a << " "; });
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