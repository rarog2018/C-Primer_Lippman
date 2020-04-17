#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob
{
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

private:
    // shared_ptr that will point to a dynamically allocated vector<string>
    shared_ptr<vector<string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const string &msg) const;
};

int main(void)
{
    StrBlob b1; // b1, 0 elems
    cout << "b1 size: " << b1.size() << endl;
    {
        StrBlob b2 = {"a", "an", "the"}; // b2, 3 elems
        cout << "b2 size: " << b2.size() << endl;
        b1 = b2; // b1, 3 elems
        cout << "after b1 = b2, b1 size: " << b1.size() << endl;

        b2.push_back("about");
        // now both b1, b2 share the same dynamically allocated vector<string>
        // so both b1 and b2 will have size 4
        cout << "after push_back(), b1 size: " << b1.size() << ", b2 size: "
             << b2.size() << endl;
    }
    // b2 does not exist anymore, but the dynamically allocated vector exist
    // and shared_ptr that is a member of b1 object points to that vector, so
    // the size of b1 is still 4
    cout << "\nAfter b2 death, b1 size: " << b1.size() << endl;

    return 0;
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
    cout << "const" << endl;
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