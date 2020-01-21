#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    /* 
    In my opinion the first program is easier to both write and read. At the 
    moment this new syntax is unfamiliar to me, even though i understand it
    I needed more time to write this than to write the previous version.
    It makes more sense if you write the full type of 'ret', but using auto
    makes it look cryptic.
    */

    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word)
    {
        // if word is already in the map insert does nothing
        auto ret = word_count.insert({word, 1});
        // so we need to check if the element was added
        if (!ret.second) // if it was not
        {
            // ret is a pair, which key is an iterator and value is a bool
            // the value was checked above in if condition - insert() returns
            // a pair which value is a bool that is false when element was
            // not added
            // iterator points to a map which has a key of type string
            // and value of type size_t, so we increment the value of type
            // size_t that is associated with string represented by 'word'
            ++ret.first->second;
        }
    }

    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }

    return 0;
}