#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef shared_ptr<vector<string>> s_pvs;
typedef shared_ptr<set<int>> s_psi;
typedef map<const string, s_psi> s_pmssi;
typedef pair<const string, set<int>> *pssi;

class QueryResult; // forward declaratio to befriend it

class TextQuery
{
public:
    // constructor
    TextQuery(ifstream &is);
    // member functions
    QueryResult query(const string &word) const;

private:
    // vector that will store the contents of the file, each string = 1 line
    s_pvs svec;
    // map that will associate each word with the set of line numbers of which
    // that word appeared
    s_pmssi susmap;
};

class QueryResult
{
    friend ostream &print(ostream &os, const QueryResult result);

public:
    // constructor
    QueryResult(s_pvs p, const string &s, s_psi q) : spSVec(p), word(s), spSUSMap(q){};

    // member function
    // ostream &print(ostream &os, QueryResult result) const;

private:
    s_pvs spSVec;
    const string word;
    s_psi spSUSMap;
};

void runQueries(ifstream &infile);
inline string make_plural(int n, const string &w, const string &e)
{
    return (n != 1) ? w + e : w;
}

int main(int argc, char *argv[])
{
    // make sure there is an argument provided
    if (argc != 2)
    {
        cout << "Incorrect number of command-line arguments" << endl;
        return 1;
    }

    ifstream iF(argv[1]);
    // if the file was succesfully open
    if (!iF)
    {
        cerr << "Could not open the file " << argv[1] << endl;
        return 2;
    }

    runQueries(iF);
    return 0;
}

// prints contents of the vector and the map
// ostream &print(ostream &os, const TextQuery &ob)
ostream &print(ostream &os, const QueryResult result)
{
    int counter;
    // calculate how many times the word
    if (result.spSUSMap->size() == 0)
        counter = 0;
    else
        counter = 0 - *result.spSUSMap->cbegin();

    os << result.word << " occurs " << counter << " " << make_plural(counter, "time", "s") << endl;

    // loop through every element in the set
    for (auto line : *result.spSUSMap)
    {
        if (line < 0)
        {
            continue;
        }
        os << "(line " << line + 1 << ") ";
        os << (*result.spSVec)[line] << endl;
    }

    return os;
}
///////////////////////////////////////////////////////////////////////////////
QueryResult TextQuery::query(const string &word) const
{
    // empty set if there was no such word
    static shared_ptr<set<int>> nodata(new set<int>);
    // check if the word is in the map
    auto it = susmap.find(word);

    if (it == susmap.end())
    {
        return QueryResult(svec, word, nodata);
    }
    // return pointer to that set
    return QueryResult(svec, word, it->second);
}

// constructor definition
TextQuery::TextQuery(ifstream &is) : svec(new vector<string>)
{
    int counter = 0;
    string line, word;

    // read each line from the file as a separate string and store it in vec
    for (int lineNum = 0; getline(is, line); ++lineNum)
    {
        (*svec).push_back(line);
        istringstream tempS(line);
        // we have to break each line into words and place them in a map
        while (tempS >> word)
        {
            // and ofcourse the line numbers will be added to the set
            auto &it = susmap[word];
            // if there is no such word in the map, insert it with lineNum
            if (!it)
            {
                it.reset(new set<int>{-1, lineNum});
            }
            // if there is append lineNum to the set
            else
            {
                it->insert(lineNum);
                // i have troubles with understanding how to count the words
                // in a way that is described in the chapter, so ill do what
                // came to my mind
                counter = *it->begin(); // store the counter
                it->erase(counter);     // erase the previous counter
                it->insert(--counter);  // add new counter
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results

    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q")
            break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}