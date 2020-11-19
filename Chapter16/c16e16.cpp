#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
using namespace std;

template <typename T>
class Vec
{
public:
    // the allocator member is default initialized
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(initializer_list<T>);    // added for tests
    Vec(const Vec &);            // copy constructor
    Vec &operator=(const Vec &); // copy assignment
    ~Vec();                      // destructor

    void push_back(const T &); // copy the element

    // size operations
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t);
    void resize(size_t, const T &);
    // another resize, because idk how to deal with default arguments in templates
    void resize(size_t);

    // "iterators"
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:
    allocator<T> alloc; // allocates the elements used by the functions
    //that add elements to the Vec
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // utilities used by the copy constructor, assignment operator, and destructor
    pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();                   // destroy the elements and free the space
    void reallocate(size_t n = 0); // get more space and copy the existing elements
    T *elements;                   // pointer to the first element in the array
    T *first_free;                 // pointer to the first free element in the array
    T *cap;                        // pointer to the one past the end of the array
};

template <typename T>
void printVec(const Vec<T> &);

int main(void)
{
    Vec<string> svec = {"WOT", "ASOIAF", "Narnia"};
    svec.push_back("Witcher");
    svec.push_back("Malazan");
    svec.push_back("LOTR");

    printVec(svec);

    Vec<int> ivec = {0, 11, 13, 7, 5, 19, 22, 19, 33, 14};
    printVec(ivec);
    return 0;
}

// print the contents of the vector
template <typename T>
void printVec(const Vec<T> &v)
{
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
// copy assign etc.
template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
    // allocate enough space
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(const Vec<T> &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

//
template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

// size operations
template <typename T>
void Vec<T>::reserve(size_t n)
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

template <typename T>
void Vec<T>::resize(size_t n, const T &s)
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

template <typename T>
void Vec<T>::resize(size_t n)
{
    // calls resize(size_t n, const T &s) with default initialized s
    resize(n, T());
}

// private members
template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair from data and the value returned by
    // uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
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

template <typename T>
void Vec<T>::reallocate(size_t n)
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