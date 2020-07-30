#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
using namespace std;

// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec
{
public:
    // the allocator member is default initialized
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>); // initializer_list constructor
    StrVec(const StrVec &);           // copy constructor

    // ADDED move members
    StrVec(StrVec &&) noexcept;            // move constructor
    StrVec &operator=(StrVec &&) noexcept; // move assignment

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
    StrVec svec{"The Witcher", "The Lord of the Rings",
                "Malazan Book of the Fallen", "Stormlight Archive",
                "The Wheel of Time"};
    cout << svec.capacity() << endl;

    StrVec svec2(std::move(svec));
    svec = std::move(svec2);
    return 0;
}

// move
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements),
                                      first_free(s.first_free), cap(s.cap)
{
    cout << "Using move constructor" << endl;
    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    cout << "Using move assignment" << endl;
    // direct test for self-assignment
    if (this != &rhs)
    {
        free();                  // free existing elements
        elements = rhs.elements; // take over resources from rhs
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
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