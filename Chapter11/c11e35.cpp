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
            //////////////////////      ANSWER      //////////////////////////
            /*
            This line will not update the value of the key if the key is already
            present in the transMap. 
            The old line (using subscript) will update the value of the key to
            the one that appeared last.

            If we have a rule file that contains these lines:
            u you
            u yours
            
            using insert() will replace each 'u' with 'you'
            using transMap[key] will replace each 'u' with 'yours'
            */
            transMap.insert({key, value.substr(1)});
            // transMap[key] = value.substr(1); // skip the space
        }
        else
        {
            cerr << "WARNING: no rule for key: " << key << endl;
            // i do not think that it is necessarry to throw exception here
            // throw runtime_error("no rule for " + key);
        }
    }
    cout << "\n"
         << transMap.size() << endl;
    return transMap;
}

const string &transform(const string &s, const map<string, string> &m)
{
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