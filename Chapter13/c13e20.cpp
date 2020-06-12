#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>
using namespace std;
using line_no = vector<string>::size_type;

///////////////////////////////////////////////////////////////////////////////
// copy: synthesized copy constructor is used and every member is copied
// assign: synthesized operator= is used and every member is assigned from
// right-hand object to left-hand object
// destroy: synthesized destructor is used and every member is destroyed
// nothing interesting happens to members that are not shared_ptr
// members that are shared_ptr are 'shared' and the reference count is increased
// or decreased (destroying)

class QueryResult; // declaration needed for return type in the query function
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

int main(void)
{
    return 0;
}