#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isprocessed(vector<string> &processed, vector<string>::const_iterator it);
int main(void)
{
    // for some reason i thought that this is from different chapter
    // way simplier it would be to just use while loop or use another vector
    // with ints and increment certain index each time word occurs
    vector<string> svec;
    vector<string> processed;
    unsigned count = 0, max_count = 0;
    string word, best;
    // store all words in a vector
    while (cin >> word)
    {
        svec.push_back(word);
    }

    // check how many times each word in the vector occured
    for (auto it = svec.cbegin(), fin = svec.cend(); it != fin; ++it)
    {
        count = 0;
        // check if it is in processed
        if (processed.empty())
        {
            processed.push_back(*it);
        }
        else if (isprocessed(processed, it))
        {
            continue;
        }
        // loop compare other elements to it

        for (auto check = svec.cbegin(); check != fin; ++check)
        {
            if (*it == *check)
            {
                ++count;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            best = *it;
        }
    }
    cout << "Unique processed words: ";
    for (auto &e : processed)
        cout << e << " ";
    cout << endl;
    cout << best << " occured " << max_count << " times." << endl;
}

bool isprocessed(vector<string> &processed, vector<string>::const_iterator it)
{
    for (auto pit = processed.cbegin(), pfin = processed.cend();
         pit != pfin; ++pit)
    {
        if (*it == *pit)
        {
            return true;
        }
    }
    processed.push_back(*it);
    return false;
}
