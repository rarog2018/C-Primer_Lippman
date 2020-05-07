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
typedef shared_ptr<map<string, set<int>>> s_pmssi;
typedef pair<const string, set<int>> *pssi;

class QueryResult; // forward declaratio to befriend it

class TextQuery
{
    // friend declarations
    friend class QueryResult;
    friend ostream &print(ostream &os, QueryResult result);

public:
    // constructors
    TextQuery();
    TextQuery(ifstream &is);

    // member functions
    // i think that it should return a QueryResult object
    QueryResult query(string &word);

private:
    // vector that will store the contents of the file, each string = 1 line
    s_pvs svec;
    // map that will associate each word with the set of line numbers of which
    // that word appeared
    s_pmssi susmap;
};

class QueryResult
{
    friend ostream &print(ostream &os, QueryResult result);

public:
    // constructor
    QueryResult(s_pvs p, pssi q) : spSVec(p), spSUSMap(q){};

    // member function
    // ostream &print(ostream &os, QueryResult result) const;

private:
    s_pvs spSVec;
    // v_tm spSUSMap;
    pssi spSUSMap;
};
// ostream &print(ostream &os, const TextQuery &ob);
void runQueries(ifstream &infile);

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
ostream &print(ostream &os, QueryResult result)
{
    // if the returned iterator is off-the-end iterator
    if (result.spSUSMap == nullptr)
    {
        os << "given word occurs 0 times" << endl;
        return os;
    }
    // calculate how many times the word
    int counter = 0 - *result.spSUSMap->second.begin();
    os << result.spSUSMap->first << " occurs " << counter << " times" << endl;

    // skip first entry in the set
    auto it = result.spSUSMap->second.cbegin();
    ++it;
    // loop through every element in the set
    for (; it != result.spSUSMap->second.cend(); ++it)
    {
        os << "(line " << *it << ") ";
        os << (*result.spSVec)[*it] << endl;
    }

    return os;
}
///////////////////////////////////////////////////////////////////////////////
QueryResult TextQuery::query(string &word)
{
    // check if the word is in the map
    auto it = (*susmap).find(word);
    pssi p(&*it); // pointer to that particular pair

    if (it == (*susmap).end())
    {
        return QueryResult(svec, nullptr);
    }
    // return pointer to that pair
    return QueryResult(svec, p);
}

// constructor definition
TextQuery::TextQuery(ifstream &is)
{
    int counter = 0;
    string line, word;
    svec = make_shared<vector<string>>();
    susmap = make_shared<map<string, set<int>>>();

    // read each line from the file as a separate string and store it in vec
    for (int lineNum = 0; getline(is, line); ++lineNum)
    {
        (*svec).push_back(line);
        istringstream tempS(line); // not sure if this is optimal
        // we have to break each line into words and place them in a map
        while (tempS >> word)
        {
            // and ofcourse the line numbers will be added to the set
            auto it = (*susmap).find(word);
            // if there is no such word in the map, insert it with lineNum
            if (it == (*susmap).end())
            {
                (*susmap).insert({word, {-1, lineNum}});
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
}
///////////////////////////////////////////////////////////////////////////////
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    // print(cout, tq);

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