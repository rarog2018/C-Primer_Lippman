#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    vector<string> exclude = {"The", "But", "And", "Or", "An", "A",
                              "the", "but", "and", "or", "an",
                              "a"};
    string word;
    while (cin >> word)
        // count only words that are not in exclude
        if (find(exclude.cbegin(), exclude.cend(), word) == exclude.cend())
            ++word_count[word];      // fetch and increment the counter for word
    for (const auto &w : word_count) // for each element in the map
        // print the results
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;

    // in this case it is hard to tell judging without comparing both versions
    // with very precise software that would measure the performance
    // the 'if' line was a little bit more complicated to write, we had to use
    // find algorithm
    // There is most likely a difference in performance, because set is supposed
    // to lookup for keys efficiently, while using a vector we had to lookup
    // every single element in the vector up untill we found a word that was
    // identical to the one that we were comparing. This means that most of the
    // times we went through all the elements in the vector.
    return 0;
}