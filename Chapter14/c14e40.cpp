#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// function-object class to be used instead of this lambda:
// [](const string &a, const string &b) { return a.size() < b.size(); }
class IsLesser
{
public:
    bool operator()(const string &a, const string &b) const { return a.size() < b.size(); }
};

// function-object class to be used instead of this lambda:
// [sz](const string &a) { return a.size() >= sz; }
class GreaterEqual
{
public:
    // constructor for the captured variable
    GreaterEqual(size_t n) : sz(n) {}

    bool operator()(const string &a) const { return a.size() >= sz; }

private:
    size_t sz;
};

// function-object class to be used instead of this lambda:
// [](const string &s) { cout << s << " "; }
class PrintString
{
public:
    void operator()(const string &s) const { cout << s << " "; }
};

void elimDups(vector<string> &words);
// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words,
             vector<string>::size_type sz)
{
    elimDups(words); // put words in alphabetical order and remove duplicates

    // sort words by size, but maintain alphabetical order for words of the same size
    // stable_sort(words.begin(), words.end(),
    //             [](const string &a, const string &b) { return a.size() < b.size(); });
    stable_sort(words.begin(), words.end(), IsLesser());

    // get an iterator to the first element whose size() is >= sz
    // auto wc = find_if(words.begin(), words.end(),
    //                   [sz](const string &a) { return a.size() >= sz; });
    auto wc = find_if(words.begin(), words.end(), GreaterEqual(sz));

    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    // for_each(wc, words.end(),
    //          [](const string &s) { cout << s << " "; });
    for_each(wc, words.end(), PrintString());
    cout << endl;
}

void printVec(vector<string> &v)
{
    for (auto &s : v)
        cout << s << " ";
    cout << endl;
}

int main(void)
{
    vector<string> svec{"we", "know", "that", "we", "can", "be", "the", "real",
                        "dragons", "of", "the", "earth", "know", "that"};

    cout << "Vector before biggies: " << endl;
    printVec(svec);

    cout << "\nBiggies: " << endl;
    biggies(svec, 5);

    cout << "\nVector after biggies: " << endl;
    printVec(svec);
    return 0;
}

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // unique reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}