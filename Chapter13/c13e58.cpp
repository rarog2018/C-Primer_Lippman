#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
    Foo() = default;               // default constructor
    Foo &operator=(const Foo &) &; // may assign only to modifiable lvalues

    // sorted declarations
    Foo sorted() &&;      // may run on modifiable rvalues
    Foo sorted() const &; // may run on any kind of Foo

    // push_back to populate the vector
    void push_back(int v) { data.push_back(v); }
    // print to print
    void print()
    {
        for (auto &e : data)
            cout << e << " ";
        cout << endl;
    }

private:
    vector<int> data;
};

int main(void)
{
    Foo ob;
    ob.push_back(17);
    ob.push_back(13);
    ob.push_back(15);
    ob.push_back(2);

    ob.print(); // prints 17 13 15 2

    // as expected the first version was calling itself untill it crashed the
    // program
    // ob.sorted();

    // as expected, the call in the return is an rvalue and uses the rvalue
    // reference sorted, the code will print messages that it uses version 2
    // followed by a message that it uses rvalue reference sorted, followed
    // by sorted elements of vector: 2 13 15 17
    ob.sorted().print();
    return 0;
}

// version 2
Foo Foo::sorted() const &
{
    cout << "Using version 2 of sorted" << endl;
    return Foo(*this).sorted();
}

// version 1
// Foo Foo::sorted() const &
// {
//     cout << "Using version 1 of sorted" << endl;
//     Foo ret(*this);
//     return ret.sorted();
// }

// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    cout << "Using rvalue reference sorted" << endl;
    sort(data.begin(), data.end());
    return *this;
}