#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Copy constructor is a constructor that initializes a new object as a copy of
// another object of the same type.
// It can be used as in our example to initialize b2 object, but also implicitly
// to pass objets to or from a function by value.
class Book
{
public:
    Book();
    Book(const string &t, unsigned pC, unsigned chC) : title(t), pageCount(pC), chapterCount(chC), contents(vector<string>(chC)) {}
    Book(const Book &ob); // copy constructor

    string title;
    unsigned pageCount, chapterCount;
    vector<string> contents;
};
// definition of copy constructor
Book::Book(const Book &ob) : title(ob.title), pageCount(ob.pageCount),
                             chapterCount(ob.chapterCount), contents(ob.contents) {}

// implicitly uses copy constructor, to create temporary object b
void print(const Book b)
{
    cout << b.title << " " << b.pageCount << " " << b.contents.size() << endl;
}
int main(void)
{
    Book b1("Baptism of Fire", 400, 27);
    cout << b1.title << " " << b1.contents.size() << endl;

    Book b2(b1); // copy constructor used to initialize b2
    cout << b2.title << " " << b2.contents.size() << endl;

    print(b1);
    return 0;
}