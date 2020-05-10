#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;
using line_no = vector<string>::size_type;

// forward declarations
class QueryResult; // declaration needed for return type in the query function
class StrBlobPtr;
class StrBlob;

// classes
class TextQuery
{
public:
    TextQuery(ifstream &is);
    QueryResult query(const string &) const;

private:
    shared_ptr<StrBlob> file; // input file
    // map of each word to the set of the lines in which that word appears
    map<string, shared_ptr<set<line_no>>> wm;
};
///////////////////////////////////////////////////////////////////////////////

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<StrBlob> f) : sought(s), lines(p), file(f) {}

    set<line_no>::iterator begin() { return lines->begin(); }
    set<line_no>::iterator end() { return lines->end(); }

    shared_ptr<StrBlob> get_file() { return file; }

private:
    string sought;                  // word this query represents
    shared_ptr<set<line_no>> lines; // lines it's on
    shared_ptr<StrBlob> file;       // input file
};
///////////////////////////////////////////////////////////////////////////////

class StrBlob
{
    friend class StrBlobPtr;

public:
    StrBlob() : data(make_shared<vector<string>>()) {} // default constructor
    // construct vector of strings from the initializer_list
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    line_no size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    string &front() const; // for const StrBlob
    string &front();       // for plain StrBlob
    string &back() const;
    string &back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    // shared_ptr that will point to a dynamically allocated vector<string>
    shared_ptr<vector<string>> data;
    // throws msg if data[i] isn't valid
    void check(line_no i, const string &msg) const;
};
//////////////////////////////////////////////////////////////////////////////

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {} // default constructor
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    string &deref() const;
    StrBlobPtr &incr(); // prefix version
private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;

    weak_ptr<vector<string>> wptr;
    size_t curr; // current position within the array
};

string make_plural(size_t ctr, const string &word, const string &ending);
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
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) : file(new StrBlob)
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
            auto &lines = wm[word];            // lines is a shared_ptr
            if (!lines)                        // that pointer is null the first time we see word
                lines.reset(new set<line_no>); // allocate a new set
            lines->insert(n);                  // insert this line number
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // not found
    else
        return QueryResult(sought, loc->second, file);
}
///////////////////////////////////////////////////////////////////////////////

ostream &print(ostream &os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
                               // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << StrBlobPtr(*qr.file, num).deref() << endl;
    return os;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
///////////////////////////////////////////////////////////////////////////////

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // is the vector still around?
    if (!ret)
    {
        throw runtime_error("StrBlobPtr doesn't point to the data member");
    }

    if (i >= ret->size())
    {
        throw out_of_range(msg);
    }

    return ret; // otherwise, return a shared_ptr to the vector
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "element out of range");
    return (*p)[curr]; // (*p) is the vector to which this object points, curr
                       // is the index of the element in the vector
}

// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
///////////////////////////////////////////////////////////////////////////////

// StrBlobPtr functions
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// private functions
void StrBlob::check(line_no i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

// member functions, again we use the members of vector class
string &StrBlob::front()
{
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
///////////////////////////////////////////////////////////////////////////////