#include <iostream>
#include <vector>
using namespace std;
class book
{
public:
    int pages;
    bool hardcover;
    book(int nmb, bool hrdc) : pages(nmb), hardcover(hrdc) {}
    // no default contructor
};
class properBook
{
public:
    int pages;
    bool hardcover;
    properBook(int nmb, bool hrdc) : pages(nmb), hardcover(hrdc) {}
    // default constructor
    properBook() : properBook(250, true) {}
};
void print_bkv(vector<book> &bvec);
void print_bkv(vector<properBook> &bvec);
int main(void)
{
    book b1(350, true), b2(190, false), b3(1399, false);
    vector<book> library{b1, b2, b3};
    print_bkv(library);
    // when we use resize that does not take the additional parameter on a
    // container that holds class objects and we are adding the elements the
    // class has to have a default constructor
    // library.resize(10);  // this will produce an error

    // 5 default initialized books
    vector<properBook> lib2(5);
    // now 5 new value initialized books will be added
    lib2.resize(10);
    print_bkv(lib2);
    return 0;
}
void print_bkv(vector<book> &bvec)
{
    cout << "Library: " << endl;
    for (const auto &e : bvec)
        cout << e.pages << " " << ((e.hardcover) ? "hardcover" : "paperback")
             << endl;
}
void print_bkv(vector<properBook> &bvec)
{
    cout << "Library: " << endl;
    for (const auto &e : bvec)
        cout << e.pages << " " << ((e.hardcover) ? "hardcover" : "paperback")
             << endl;
}