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

// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec
{
public:
    // the allocator member is default initialized
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    // ADDED: new constructor that takes an initializer list, to initialize
    // the 'vector'
    StrVec(initializer_list<string>);
    StrVec(const StrVec &);            // copy constructor
    StrVec &operator=(const StrVec &); // copy assignment
    ~StrVec();                         // destructor

    void push_back(const string &); // copy the element

    // size operations
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t);
    void resize(size_t, const string &s = "");

    // "iterators"
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    allocator<string> alloc; // allocates the elements used by the functions
    //that add elements to the StrVec
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // utilities used by the copy constructor, assignment operator, and destructor
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();                   // destroy the elements and free the space
    void reallocate(size_t n = 0); // get more space and copy the existing elements
    string *elements;              // pointer to the first element in the array
    string *first_free;            // pointer to the first free element in the array
    string *cap;                   // pointer to the one past the end of the array
};

class TextQuery
{
public:
    TextQuery(ifstream &is);
    QueryResult query(const string &) const;

private:
    shared_ptr<StrVec> file; // input file
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
                shared_ptr<StrVec> f) : sought(s), lines(p), file(f) {}

    set<line_no>::iterator begin() { return lines->begin(); }
    set<line_no>::iterator end() { return lines->end(); }

    shared_ptr<StrVec> get_file() { return file; }

private:
    string sought;                  // word this query represents
    shared_ptr<set<line_no>> lines; // lines it's on
    shared_ptr<StrVec> file;        // input file
};
///////////////////////////////////////////////////////////////////////////////

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
TextQuery::TextQuery(ifstream &is) : file(new StrVec)
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
           << (*qr.file, num) << endl;
    return os;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

//////////////////////////////////////////////////////////////////////////////

StrVec::StrVec(initializer_list<string> il)
{
    cout << "Using initializer list constructor" << endl;
    // this looks oddly similar to copy constructor, so maybe a delegating
    // constructor would be appropriate
    auto newData = alloc_n_copy(il.begin(), il.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

//////////////////////////////////////////////////////////////////////////////
void StrVec::resize(size_t n, const string &s)
{
    // if the current size is greater than requested size the elements from
    // the back of the container will be deleted
    if (n < size())
    {
        for (size_t i = size() - n; i != 0; --i)
        {
            // destroy the elements to which decremented first_free points
            alloc.destroy(--first_free);
        }
    }
    // if the requested size is greater than the requested size, push_back
    // elements to the container
    else if (n > size())
    {
        for (size_t i = n - size(); i != 0; --i)
        {
            push_back(s);
        }
    }
}

void StrVec::reserve(size_t n)
{
    // reserve does nothing if n does not exceed the current capacity
    if (n <= capacity())
    {
        return;
    }
    // when n is less than capacity * 2 reallocate with double capacity
    else if (n <= capacity() * 2)
    {
        reallocate(capacity() * 2);
    }
    // if n is greater than double capacity reallocate to n elements
    else
    {
        reallocate(n);
    }
}
///////////////////////////////////////////////////////////////////////////////
void StrVec::push_back(const string &s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair from data and the value returned by
    // uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
    if (elements)
    {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != elements; /*empty*/)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate(size_t n)
{
    cout << "Using reallocate() with capacity " << capacity() << endl;
    unsigned long long newcapacity = 0;
    // if the function was called with the default argument, double the capacity
    if (!n)
    {
        // we'll allocate space for twice as many elements as the current size
        newcapacity = size() ? 2 * size() : 1;
    }
    // else use the argument to determine newcapacity
    else
    {
        newcapacity = n;
    }
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // move the data from the old memory to the new
    auto dest = newdata;  // points to the next free position in the array
    auto elem = elements; // points to the next element in old array
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free(); // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}