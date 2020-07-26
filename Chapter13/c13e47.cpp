#include <iostream>
#include <memory>
using namespace std;

// class that imitates string
class String
{
public:
    String() : first_element(nullptr), first_free(nullptr), cap(nullptr) {}
    // constructor that takes a pointer to a C-like string, it will work
    // similarly to the constructor that took initializer list in StrVec class
    String(char *);
    String(const String &);            // copy constructor
    String &operator=(const String &); // copy assignment operator
    ~String() { free(); }              //destructor

    // append to String
    void push_back(const char &);

    // size operations
    size_t size() const { return first_free - first_element; }
    size_t capacity() const { return cap - first_element; }

    // "iterators"
    char *begin() const { return first_element; }
    char *end() const { return first_free; }

private:
    char *first_element;   // pointer to the first element in the string
    char *first_free;      // pointer to the first free element in the string
    char *cap;             // pointer to the one past the end of the string
    allocator<char> alloc; // allocates char elements
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void free();       // destroy the elements and free the space
    void reallocate(); // get more space and copy the existing elements
};

// overloading << operator for better immersion
ostream &operator<<(ostream &os, const String &s);

int main(void)
{
    String s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('p');
    s.push_back('!');

    cout << "size: " << s.size() << endl;
    cout << "capacity: " << s.capacity() << endl;
    cout << s << endl;

    String s2(s);
    cout << &s.begin()[0] << " " << &s2.begin()[0] << endl;
    cout << s2 << endl;

    char cstring[] = "a word";
    String s3(cstring);
    cout << s3 << endl;

    String s4;
    s4 = s2;
    s4 = s4;
    cout << s4 << endl;
    return 0;
}

ostream &operator<<(ostream &os, const String &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        os << *it;
    return os;
}

String::String(char *p)
{
    cout << "Using C-style constructor" << endl;
    // we will visit each character in the C-style string untill we meet null
    while (*p != '\0')
        push_back(*p++);
}

String::String(const String &s)
{
    cout << "Using copy constructor" << endl;
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(s.end() - s.begin());
    auto pString = uninitialized_copy(s.begin(), s.end(), data);

    first_element = data;
    first_free = cap = pString;
}

String &String::operator=(const String &s)
{
    cout << "Using copy-assignment operator" << endl;
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(s.end() - s.begin());
    auto pString = uninitialized_copy(s.begin(), s.end(), data);
    free();
    first_element = data;
    first_free = cap = pString;
    return *this;
}

void String::push_back(const char &c)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, c);
}

void String::free()
{
    // may not pass deallocate a 0 pointer; if first_el is 0, there's no work to do
    if (first_element)
    {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != first_element; /*empty*/)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(first_element, cap - first_element);
    }
}

void String::reallocate()
{

    // we'll allocate space for twice as many elements as the current size
    size_t newcapacity = size() ? 2 * size() : 1;

    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // move the data from the old memory to the new
    auto dest = newdata;       // points to the next free position in the array
    auto elem = first_element; // points to the next element in old array
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free(); // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    first_element = newdata;
    first_free = dest;
    cap = first_element + newcapacity;
}