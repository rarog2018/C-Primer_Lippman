#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// forward declaration to befriend the class
class StrBlobPtr;

class StrBlob
{
    // befriend StrBlobPtr
    friend class StrBlobPtr;

public:
    // type alias for readability purposes
    typedef vector<string>::size_type size_type;

    // constructors
    StrBlob() : data(make_shared<vector<string>>()) {} // default constructor
    // construct vector of strings from the initializer_list
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    // member functions
    // check the size of the dynamically allocated vector to which shared_ptr points
    size_type size() const { return data->size(); }
    // check if the vector<string> is empty, both functions use members of vector
    bool empty() const { return data->empty(); }

    // functions that add and remove elements
    // this function can be defined here, because no matter if vector is empty
    // we can add elements to it (we use vec.push_back() member)
    void push_back(const string &t) { data->push_back(t); }
    // before we pop the element from the back of the vector we have to check
    // if the vector is empty
    void pop_back();

    // functions that access the elements in the vector<string>
    // element access, again we define them elsewhere, because we need to check
    // whether the vector is empty
    string &front() const; // for const StrBlob
    string &front();       // for plain StrBlob
    string &back() const;
    string &back();

    // StrBlobPtr members
    // return StrBlobPtr to the first and one past the last elements, so pretty
    // much mimic the iterators c.begin(), c.end()
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    // shared_ptr that will point to a dynamically allocated vector<string>
    shared_ptr<vector<string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const string &msg) const;
};
//////////////////////////////////////////////////////////////////////////////

// StrBlobPtr throws an exception on attempts to access a nonexistent element
// object of this class is used as a sort of iterator for StrBlob object
class StrBlobPtr
{
public:
    // constructors
    StrBlobPtr() : curr(0) {} // default constructor
    // wptr will point to first el in vector<string> data
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    // member functions
    // fetch the string underneath vector<string>, but don't change it
    string &deref() const;
    StrBlobPtr &incr(); // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    // we cannot dereference a weak_ptr but thanks to it we'll know if it is
    // safe to access given element, if so, return shared_ptr
    shared_ptr<vector<string>> check(size_t i, const string &msg) const;

    // store a weak_ptr, which means the underlying vector might be destroyed
    weak_ptr<vector<string>> wptr;
    size_t curr; // current position within the array
};

int main(void)
{
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
void StrBlob::check(size_type i, const string &msg) const
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