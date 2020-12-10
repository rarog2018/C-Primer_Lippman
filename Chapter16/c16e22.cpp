#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <memory>
using namespace std;

using line_no = vector<string>::size_type;

// function-object class
class DebugDelete
{
public:
    DebugDelete(const string &w, ostream &s = cerr) : what(w), os(s){};

    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting pointer to [" << what << "] with value: ";
        // this shows us what gets deleted
        /*
        if (what == "Line Set")
        {
            for (auto e : *p)
            {
                os << &e << " ";
            }
        }
        */
        os << endl;
        delete p;
    }

private:
    ostream &os;
    string what;
};

class QueryResult; // declaration needed for return type in the query function
class TextQuery
{
public:
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    shared_ptr<map<string, shared_ptr<set<line_no>>>> wm;
};

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

private:
    string sought;                   // word this query represents
    shared_ptr<set<line_no>> lines;  // lines it's on
    shared_ptr<vector<string>> file; // input file
};

string make_plural(size_t ctr, const string &, const string &);
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

///////////////////////////////////////////////////////////////////////////////
// TextQuery
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) : file(new vector<string>, DebugDelete("File")), wm(new map<string, shared_ptr<set<line_no>>>(), DebugDelete("Vector"))
{
    string text;
    while (getline(is, text))
    {                             // for each line in the file
        file->push_back(text);    // remember this line of text
        int n = file->size() - 1; // the current line number
        istringstream line(text); // separate the line into words
        string word;
        while (line >> word)
        { // for each word in that line
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = (*wm)[word];                                  // lines is a shared_ptr
            if (!lines)                                                 // that pointer is null the first time we see word
                lines.reset(new set<line_no>, DebugDelete("Line Set")); // allocate a new set
            lines->insert(n);                                           // insert this line number
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>, DebugDelete("Static Set"));
    // use find and not a subscript to avoid adding words to wm!
    auto loc = (*wm).find(sought);
    if (loc == (*wm).end())
        return QueryResult(sought, nodata, file); // not found
    else
        return QueryResult(sought, loc->second, file);
}

///////////////////////////////////////////////////////////////////////////////
// QueryResult
ostream &print(ostream &os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
                               // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}