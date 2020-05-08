#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;

void printResult(string &s, unique_ptr<vector<string>> &svec, unique_ptr<map<const string, set<int>>> &ms);

int main(int argc, char *argv[])
{
    // make sure there is an argument provided if (argc != 2)
    if (argc != 2)
    {
        cerr << "Incorrect number of command-line arguments" << endl;
        return 1;
    }

    ifstream iF(argv[1]);
    // if the file was succesfully open
    if (!iF)
    {
        cerr << "Could not open the file " << argv[1] << endl;
        return 2;
    }

    // will hold the file contents
    unique_ptr<vector<string>> upSVec(new vector<string>());
    // will hold each word and corresponding lines
    unique_ptr<map<const string, set<int>>> upMssi(new map<const string, set<int>>());

    string line, word;
    int counter = 0;

    // read each line from the file as a separate string and store it in vec
    for (int lineNum = 0; getline(iF, line); ++lineNum)
    {
        (*upSVec).push_back(line);
        istringstream tempS(line); // not sure if this is optimal
        // we have to break each line into words and place them in a map
        while (tempS >> word)
        {
            // and ofcourse the line numbers will be added to the set
            auto it = (*upMssi).find(word);
            // if there is no such word in the map, insert it with lineNum
            if (it == (*upMssi).end())
            {
                (*upMssi).insert({word, {-1, lineNum}});
            }
            // if there is append lineNum to the set
            else
            {
                it->second.insert(lineNum);
                // i have troubles with understanding how to count the words
                // in a way that is described in the chapter, so ill do what
                // came to my mind
                counter = *it->second.begin(); // store the counter
                it->second.erase(counter);     // erase the previous counter
                it->second.insert(--counter);  // add new counter
            }
        }
    }

    // interact with the user
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q")
            break;

        printResult(s, upSVec, upMssi);
    }
    return 0;
}
void printResult(string &s, unique_ptr<vector<string>> &svec, unique_ptr<map<const string, set<int>>> &ms)
{
    auto it = (*ms).find(s);
    // check if the word was found
    if (it == (*ms).end())
    {
        cout << s << " occurs 0 times" << endl;
        return;
    }

    // p points to the beginning of the set
    auto p = it->second.begin();
    int counter = 0 - *p; // absolute value of counter
    cout << s << " occurs " << counter << " times" << endl;

    // loop through each value in the set
    for (++p; p != it->second.end(); ++p)
    {
        cout << "(line " << *p << ") " << (*svec)[*p] << endl;
    }
    cout << endl;
}