#include <iostream>
#include <string>
#include <memory>
#include <utility>
using namespace std;

// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec
{
public:
    // the allocator member is default initialized
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
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

void print(const StrVec &sv)
{
    size_t i = 0;
    for (auto it = sv.begin(); i != sv.size(); ++i, ++it)
    {
        cout << *it << ", ";
        if (!((i + 1) % 5))
        {
            cout << endl;
        }
    }
}
int main(void)
{
    StrVec svec;
    cout << svec.capacity() << endl;
    svec.push_back("The Witcher");
    svec.push_back("The Lord of the Rings");
    svec.push_back("Malazan Book of the Fallen");
    svec.push_back("Stormlight Archive");
    svec.push_back("The Wheel of Time");

    // reserve tests
    cout << svec.capacity() << endl;
    svec.reserve(17);
    cout << svec.capacity() << endl;
    for (size_t i = svec.size(); i != svec.capacity(); ++i)
    {
        svec.push_back("temp");
    }
    cout << svec.capacity() << endl;
    print(svec);
    svec.push_back("A Song of Ice and Fire");
    cout << svec.capacity() << endl;

    // resize tests
    cout << "Before resize: " << svec.size() << endl;
    svec.resize(25, "newEl");
    cout << "After resize: " << svec.size() << endl;
    print(svec);

    svec.resize(10);
    cout << "New resize: " << svec.size() << endl;
    cout << svec.capacity() << endl;
    print(svec);
    return 0;
}

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