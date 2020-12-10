#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>
using namespace std;

// forward declarations needed for friend declarations in Blob
template <typename>
class BlobPtr;

template <typename T>
class Blob
{
    friend class BlobPtr<T>;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T> il);

    // template constructor that takes iterators
    // it constructs the vector 'data' member from the given range
    template <typename It>
    Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

    // number of elements in the blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const T &t) { data->push_back(t); }
    // move version
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    // element access
    T &back();
    const T &back() const;
    T &front();
    const T &front() const;
    T &operator[](size_type i);
    const T &operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] is not valid
    void check(size_type i, const std::string &msg) const;
};

// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T>
class BlobPtr
{
    template <typename F>
    friend bool operator==(const BlobPtr<F> &, const BlobPtr<F> &);
    template <typename F>
    friend bool operator<(const BlobPtr<F> &, const BlobPtr<F> &);

public:
    // constructors
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    // dereference
    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; // (*p) is the vector to which this object points
    }

    // increment and decrement
    BlobPtr &operator++(); // prefix operators
    BlobPtr &operator--();

    // The above is same as
    /*
    BlobPtr<T>& operator++();
    BlobPtr<T>& operator--();
    */
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; // current position within the array
};

int main(void)
{
    Blob<int> bi = {0, 17, 3, 5, 8, 2, 19, 11};
    BlobPtr<int> pbi(bi);

    cout << *pbi << endl;
    ++pbi;
    cout << *pbi << endl;
    ++pbi;

    BlobPtr<int> pbi2(bi, 1);

    cout << *pbi << ", " << *pbi2 << endl;

    // Comparison tests
    cout << *pbi << " < " << *pbi2 << " : " << ((pbi < pbi2) ? "true" : "false") << endl;
    cout << *pbi2 << " < " << *pbi << " : " << ((pbi2 < pbi) ? "true" : "false") << endl;

    // Iterator constructor tests
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    Blob<int> bi2(begin(ia), end(ia));
    cout << bi2.front() << endl;

    Blob<long> bl(vi.begin(), vi.end());
    cout << bl.front() << endl;

    for (auto it = bl.front(); it != bl.back(); ++it)
        cout << it << " ";
    cout << endl;
    cout << bl[9] << endl;
    return 0;
}

// operator definitions
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    // check if both pointers point to the same container
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw runtime_error("Can't compare different containers");
    }
    return lhs.curr == rhs.curr; // test whether they point to the same element
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    // check if both pointers point to the same container
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw runtime_error("Can't compare different containers");
    }
    return *lhs < *rhs; // compare the values to which Ptr point
}

///////////////////////////////////////////////////////////////////////////////
// Blob

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

// access members
template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T &Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    // if i is too big, check will throw, preventing access to a nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

// constructors
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

///////////////////////////////////////////////////////////////////////////////
// BlobPtr
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw runtime_error("BlobPtr<T> doesn't point to the data member");
    }

    if (i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

// prefix:
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    // have to check if we are not outside of the container
    check(curr, "we are outside of the container");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    // have to check if we are not outside of the container
    check(curr, "we are outside of the container");
    --curr;
    return *this;
}

// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this; // save the current value
    // same as: BlobPtr<T> ret = *this;
    ++*this;    // advance one element; prefix ++ checks the increment
    return ret; // return the saved state
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this; // save the current value
    // same as: BlobPtr<T> ret = *this;
    --*this;    // advance one element; prefix ++ checks the increment
    return ret; // return the saved state
}