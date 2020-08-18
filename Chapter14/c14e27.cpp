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

    // copy constructor
    StrBlob(const StrBlob &o) : data(make_shared<vector<string>>(*o.data)) {}
    // copy-assignment operator
    StrBlob &operator=(const StrBlob &);

    // subscript operators
    string &operator[](size_t n) { return (*data)[n]; }
    const string &operator[](size_t n) const { return (*data)[n]; }

    line_no size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    // rvalue reference version
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

    // subscript operators
    string &operator[](size_t n) { return (*wptr.lock())[n]; }
    const string &operator[](size_t n) const { return (*wptr.lock())[n]; }

    // ADDED: increment and decrement operators
    // increment and decrement
    StrBlobPtr &operator++(); // prefix operators
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int); // postfix operators
    StrBlobPtr operator--(int);

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
    StrBlob ob1;
    ob1.push_back("The Witcher");
    ob1.push_back("The Lord of the Rings");
    ob1.push_back("Malazan Book of the Fallen");
    ob1.push_back("Stormlight Archive");

    // increment and decrement operators tests
    // prefix
    StrBlobPtr p(ob1); // p points to the vector inside ob1
    cout << "p points to: " << p.deref() << endl;
    cout << "calling prefix increment operator twice" << endl;
    p.operator++(); // call prefix operator++
    ++p;
    cout << "p points to: " << p.deref() << endl;
    cout << "calling prefix decrement operator once" << endl;
    --p;
    cout << "p points to: " << p.deref() << endl;

    // postfix
    cout << "\ncall to the postfix increment operator yields: ";
    auto a = p.operator++(0); // call postfix operator++
    cout << a.deref() << endl;
    cout << "p points to: " << p.deref() << endl;
    cout << "calling postfix decrement operator once yields: ";
    a = p--;
    cout << a.deref() << endl;
    cout << "p points to: " << p.deref() << endl;
    return 0;
}

// Incrementation and decrementation operators definitions
// postfix: increment/decrement the object but return the unchanged value
StrBlobPtr StrBlobPtr::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    StrBlobPtr ret = *this; // save the current value
    ++*this;                // advance one element; prefix ++ checks the increment
    return ret;             // return the saved state
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    // no check needed here; the call to prefix decrement will do the check
    StrBlobPtr ret = *this; // save the current value
    --*this;                // move backward one element; prefix -- checks the decrement
    return ret;             // return the saved state
}

// prefix: return a reference to the incremented/decremented object
StrBlobPtr &StrBlobPtr::operator++()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
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