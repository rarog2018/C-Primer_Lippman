#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
using line_no = vector<string>::size_type;

// forward declaration to befriend the class
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

public:
    StrBlob() : data(make_shared<vector<string>>()) {} // default constructor
    // construct vector of strings from the initializer_list
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    // NEW: copy constructor
    StrBlob(const StrBlob &o) : data(make_shared<vector<string>>(*o.data)) {}
    // NEW: copy-assignment operator
    StrBlob &operator=(const StrBlob &);

    line_no size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    // ADDED rvalue reference version
    void push_back(const string &&t) { data->push_back(std::move(t)); }
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

// operator= definition
StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}
int main(void)
{
    StrBlob ob1, ob3;
    ob1.push_back("Witcher");
    ob1.push_back("LOTR");
    StrBlob ob2(ob1);
    ob3 = ob1;
    ob1.pop_back();
    ob1.pop_back();
    ob1.push_back("WOT");
    ob2.push_back("Malazan");

    cout << ob1.front() << " " << ob1.back() << endl;
    cout << ob2.front() << " " << ob2.back() << endl;
    cout << ob3.front() << " " << ob3.back() << endl;
    return 0;
}

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
///////////////////////////////////////