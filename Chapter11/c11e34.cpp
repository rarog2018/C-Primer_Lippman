#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void word_transform(ifstream &rules, ifstream &text);
map<string, string> build_map(ifstream &rules);
const string &transform(const string &s, const map<string, string> &m);

int main(void)
{
    // file that will contain the rules for the transformations
    ifstream rulesFile("rules.txt");
    // try to open it
    if (!rulesFile.is_open())
    {
        cerr << "Failed to open rules.txt" << endl;
        return 1;
    }

    // file with the text to transform
    ifstream textFile("text.txt");
    // try to open it
    if (!textFile.is_open())
    {
        cerr << "Failed to open text.txt" << endl;
        return 2;
    }

    //
    word_transform(rulesFile, textFile);
    return 0;
}

void word_transform(ifstream &rules, ifstream &text)
{
    auto ruleMap = build_map(rules); // store the transformations
    string line;                     // hold each line from the input
    while (getline(text, line))      // read a line of input
    {
        istringstream stream(line); // read each word
        string word;
        bool firstWord = true; // controls wheter a space is printed
        while (stream >> word)
        {
            if (firstWord)
            {
                firstWord = false;
            }
            else
            {
                cout << " "; // print a space between words
            }
            // transform returns its first argument or its transformation
            cout << transform(word, ruleMap); // print the output
        }
        cout << endl; // done with this line of input
    }
}

map<string, string> build_map(ifstream &rules)
{
    map<string, string> transMap; // holds the transformations
    string key;                   // a word to transform
    string value;                 // phrase to use instead
    // read the first word into key and the rest of the line into value
    while (rules >> key && getline(rules, value))
    {
        if (value.size() > 1) // check that there is a tranformation
        {
            transMap[key] = value.substr(1); // skip the space
        }
        else
        {
            cerr << "WARNING: no rule for key: " << key << endl;
            // i do not think that it is necessarry to throw exception here
            // throw runtime_error("no rule for " + key);
        }
    }
    return transMap;
}

const string &transform(const string &s, const map<string, string> &m)
{
    //////////////////////////      ANSWER      /////////////////////////////
    /*
    It is not possible to use subscript instead of find() because we cannot
    subscript a const map. Subscript operator adds an element if it is not in
    the map already, so it cannot be used on the const object.
    If we were not working on a const map, we would be adding a new word to the
    rule map each time we would occur the word that is not in that map.
    The problem is that we would not be adding a rule, because the value of the
    pair would be value initialized to an empty string.
    So when we would occur the word second time in the text it would be replaced
    with an empty string. 
    */
    // auto mapIt = m[s];
    // the actual map work; this part is the heart of the program
    auto mapIt = m.find(s);
    // if this word is in the transformation map
    if (mapIt != m.cend())
    {
        return mapIt->second; // use the replacement word
    }
    else
    {
        return s; // return the original word
    }
}