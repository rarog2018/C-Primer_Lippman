#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cctype>
using namespace std;
using line_no = vector<string>::size_type;

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) { cout << "QueryResult::QueryResult(string, sh_ptr, sh_ptr)" << endl; }

    set<line_no>::iterator begin() { return lines->begin(); }
    set<line_no>::iterator end() { return lines->end(); }

    shared_ptr<vector<string>> get_file() { return file; }

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

private:
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
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const
    {
        cout << "Query::rep()" << endl;
        return q->rep();
    }

private:
    Query(shared_ptr<Query_base> query) : q(query)
    {
        cout << "Using Query::Query(shared_ptr<Query_base>)" << endl;
    }
    shared_ptr<Query_base> q;
};

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q)
    {
        cout << "Using NotQuery::NotQuery(const Query &)" << endl;
    }
    // concrete class: NotQuery defines all inherited pure virtual functions
    string rep() const
    {
        cout << "NotQuery::rep()" << endl;
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s)
    {
        cout << "Using BinaryQuery::BinaryQuery(const Query &, const Query &, string)" << endl;
    }
    // abstract class: BinaryQuery doesn't define eval
    string rep() const
    {
        cout << "BinaryQuery::rep()" << endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs; // right- and left-hand operands
    string opSym;   // name of the operator
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&")
    {
        cout << "Using AndQuery::AndQuery(const Query &, const Query &)" << endl;
    }
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|")
    {
        cout << "Using OrQuery::OrQuery(const Query &, const Query)" << endl;
    }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &, const Query &);
inline Query operator&(const Query &, const Query &);
inline Query operator~(const Query &);
string make_plural(size_t ctr, const string &, const string &);
ostream &operator<<(ostream &, const Query &);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    ifstream iFile("input.txt");
    TextQuery tq(iFile);

    Query daddy("Daddy");                                // Query for "Daddy"
    Query notAlice = ~Query("Alice");                    // Query for ~(Alice)
    Query hairOrAlice = Query("hair") | Query("Alice");  // Alice or hair
    Query hairAndAlice = Query("hair") & Query("Alice"); // Alice & hair
    Query q = Query("fiery") & Query("bird") | Query("wind");

    // The results will be printed at the very bottom of the program
    print(cout, daddy.eval(tq));
    cout << endl;

    print(cout, notAlice.eval(tq));
    cout << endl;

    print(cout, hairOrAlice.eval(tq));
    cout << endl;

    print(cout, hairAndAlice.eval(tq));
    cout << endl;

    print(cout, q.eval(tq));
    cout << endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// ORQUERY
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

// returns the union of its operands' result sets
QueryResult OrQuery::eval(const TextQuery &text) const
{
    // virtual calls through the Query members, lhs and rhs
    // the calls to eval return the QueryResult for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);
    // copy the line numbers from the left-hand operand into the result set
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    // insert lines from the right-hand operand
    ret_lines->insert(right.begin(), right.end());
    // return the new QueryResult representing the union of lhs and rhs
    return QueryResult(rep(), ret_lines, left.get_file());
}

// ANDQUERY
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

// returns the intersection of its operands' result sets
QueryResult AndQuery::eval(const TextQuery &text) const
{
    // virtual calls through the Query operands to get result sets for the operands
    auto left = lhs.eval(text), right = rhs.eval(text);
    // set to hold the intersection of left and right
    auto ret_lines = make_shared<set<line_no>>();
    // writes the intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// NOTQUERY
inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

// returns the lines not in its operand's result set
QueryResult NotQuery::eval(const TextQuery &text) const
{
    // virtual call to eval through the Query operand
    auto result = query.eval(text);
    // start out with an empty result set
    auto ret_lines = make_shared<set<line_no>>();
    // we have to iterate through the lines on which our operand appears
    auto beg = result.begin(), end = result.end();
    // for each line in the input file, if that line is not in result,
    // add that line number to ret_lines
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        // if we haven't processed all the lines in result
        // check whether this line is present
        if (beg == end || *beg != n)
            ret_lines->insert(n); // if not in result, add this line
        else if (beg != end)
            ++beg; // otherwise get the next line number in result if there is one
    }
    return QueryResult(rep(), ret_lines, result.get_file());
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
            // get rid of punctuation
            string result;
            copy_if(word.begin(), word.end(), back_inserter(result), ptr_fun<int, int>(&isalnum));

            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[result];          // lines is a shared_ptr
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