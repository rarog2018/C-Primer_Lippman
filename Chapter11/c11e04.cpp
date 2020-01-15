#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int alphaDiff = 'a' - 'A';
    // store the words and their count in a map
    map<string, int> wordCount;
    // store punctation characters in a set
    set<char> sPunc{'/', '.', ',', '?', '!', '"', ':', ';', '(', ')'};
    // set with capital letters
    set<char> sCap{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'W', 'X', 'Y', 'Z'};
    string word, temp;

    // read a sequence
    while (cin >> word)
    {
        temp = ""; // reset temp, final destination container for each :) word
        // go through each character in the word, capture two local variables
        // as references, 'c' will be a temporary storage for whichever character
        // for_each algorithm proceeds in lambda's function body we check if
        // the character 'c' is in sPunc set, if it is not we add the character
        // to the temp variable, if it is we do nothing to temp
        for_each(word.cbegin(), word.cend(), [&temp, &sPunc](const char &c) { (sPunc.find(c) == sPunc.end()) ? temp += c : temp; });

        // after we proceeded the whole word, we check if temp starts with
        // uppercase letter, if so we convert it to lowercase
        if (sCap.find(temp[0]) != sCap.end())
        {
            temp[0] += alphaDiff;
        }
        // place each word as a key in the map and increment its counter
        // if the word is not in the map already the new entry will occur with
        // counter set to 0, which will be immediately incremented
        ++wordCount[temp];
    }

    // print how many times each word occured
    for (const auto &e : wordCount)
    {
        cout << e.first << " occured " << e.second << " times" << endl;
    }
    return 0;
}