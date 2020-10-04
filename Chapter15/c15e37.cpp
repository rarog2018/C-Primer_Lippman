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

// There are not that many changes in code, because a Query is basically a
// shared_ptr to a dynamically allocated Query_base, but the changes are very
// significant. We basically throw away the encapsulation, the members of ceratin
// classes have to be public, and that is not what we want.

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) { cout << "QueryResult::QueryResult(string, sh_ptr, sh_ptr)" << endl; }

private:
    string sought;                   // word this query represents
    shared_ptr<set<line_no>> lines;  // lines it's on
    shared_ptr<vector<string>> file; // input file
};

class TextQuery
{
public:
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    map<string, shared_ptr<set<line_no>>> wm;
};

// abstract class acts as a base class for concrete query types; all members are private
class Query_base
{
    friend class Query;

protected:
    virtual ~Query_base() = default;

public:
    // eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery &) const = 0;
    // rep is a string representation of the query
    virtual string rep() const = 0;
};

class WordQuery : public Query_base
{
    friend class Query; // Query uses the WordQuery constructor
    WordQuery(const string &s) : query_word(s)
    {
        cout << "Using WordQuery::WordQuery(const string &)" << endl;
    }
    // concrete class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    string rep() const
    {
        cout << "WordQuery::rep()" << endl;
        return query_word;
    }
    string query_word; // word for which to search
};

// interface class to manage the Query_base inheritance hierarchy
class Query
{
    // these operators need access to the shared_ptr constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    // Query(const string &); // builds a new WordQuery
    Query(const string &s) : q(new WordQuery(s))
    {
        cout << "Using Query::Query(const string &)" << endl;
    }
    // interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery &) const;
    string rep() const
    {
        cout << "Query::rep()" << endl;
        return q->rep();
    }

    // private:
    Query(shared_ptr<Query_base> query) : q(query)
    {
        cout << "Using Query::Query(shared_ptr<Query_base>)" << endl;
    }
    shared_ptr<Query_base> q;
};

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    // NotQuery(const Query &q) : query(q)
    NotQuery(shared_ptr<Query_base> q) : query(q)
    {
        cout << "Using NotQuery::NotQuery(shared_ptr<Query_base>)" << endl;
    }
    // concrete class: NotQuery defines all inherited pure virtual functions
    string rep() const
    {
        cout << "NotQuery::rep()" << endl;
        return "~(" + query->rep() + ")";
    }
    QueryResult eval(const TextQuery &t) const { return t.query("c"); }
    // Query query;
    shared_ptr<Query_base> query;
};

class BinaryQuery : public Query_base
{
protected:
    // BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s)
    BinaryQuery(shared_ptr<Query_base> l, shared_ptr<Query_base> r, string s) : lhs(l), rhs(r), opSym(s)
    {
        cout << "Using BinaryQuery::BinaryQuery(shared_ptr<Query_base>, shared_ptr<Query_base>, string)" << endl;
    }
    // abstract class: BinaryQuery doesn't define eval
    string rep() const
    {
        cout << "BinaryQuery::rep()" << endl;
        return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")";
    }
    // Query lhs, rhs; // right- and left-hand operands
    shared_ptr<Query_base> lhs, rhs;
    string opSym; // name of the operator
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left.q, right.q, "&")
    {
        cout << "Using AndQuery::AndQuery(const Query &, const Query &)" << endl;
    }
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery &t) const { return t.query("a"); };
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left.q, right.q, "|")
    {
        cout << "Using OrQuery::OrQuery(const Query &, const Query)" << endl;
    }
    QueryResult eval(const TextQuery &t) const { return t.query("b"); };
};

Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);
Query operator~(const Query &);
string make_plural(size_t ctr, const string &, const string &);
ostream &operator<<(ostream &, const Query &);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    Query q = Query("fiery") & Query("bird") | Query("wind");

    cout << endl;
    cout << q;
    return 0;
}

// ORQUERY
Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs.q, rhs.q));
}

// ANDQUERY
Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

// NOTQUERY
Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand.q));
}

// QUERY
ostream &operator<<(ostream &os, const Query &query)
{
    // Query::rep makes a virtual call through its Query_base pointer to rep()
    return os << query.rep();
}

// QUERYRESULT
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

// TEXTQUERY
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
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