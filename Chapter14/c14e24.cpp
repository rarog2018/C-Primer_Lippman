#include <iostream>
#include <vector>
#include <string>
using namespace std;

// This class doesn't need a copy- and move-assignment operators, because
// the synthesized versions can deal with these tasks correctly
// There is no fancy memory allocation to deal with, so the synthesized versions
// do not have anything more to do than to memberwise copy or move

class Book
{
    // friend declarations
    friend ostream &operator<<(ostream &, const Book &); // output operator
    friend istream &operator>>(istream &, Book &);       // input operator
    // equality operators
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);

public:
    // constructors
    Book(string s = "", string as = "") : title(s), author(as) {}
    Book(unsigned nop, string t, string a, double p) : pageNum(nop), title(t), author(a), price(p) {}
    Book(istream &); // istream constructor uses overloaded >> operator

    // getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    unsigned getPageCount() const { return pageNum; }
    double getPrice() const { return price; }

    // setters
    void setTitle(string &t) { title = t; }
    void setAuthor(string &a) { author = a; }
    void setPageCount(unsigned pc) { pageNum = pc; }
    void setPrice(double p) { price = p; }

private:
    unsigned pageNum = 0;
    string title;
    string author;
    double price = 10.0;
};

int main(void)
{
    Book b1(350, "Baptism of Fire", "Andrzej Sapkowski", 25);
    Book b2(900, "Potop", "Henryk Sienkiewicz", 44.99);
    Book b3(415, "Baptism of Fire", "Andrzej Sapkowski", 29.5);

    // equality operator tests
    cout << "b1 == b2: " << ((b1 == b2) ? "true" : "false") << endl;
    cout << "b1 == b3: " << ((b1 == b3) ? "true" : "false") << endl;
    cout << "b2 != b3: " << ((b2 != b3) ? "true" : "false") << endl;
    return 0;
}

// equality operators definitions
bool operator==(const Book &lhs, const Book &rhs)
{
    // theoreticaly it should compare every member, but if the books have same
    // tittle and same authors they are the same book regardles of page count
    // and price of the book
    return lhs.getTitle() == rhs.getTitle() &&
           lhs.getAuthor() == rhs.getAuthor();
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs); // delegate the work to == operator
}

// input operator
istream &operator>>(istream &is, Book &b)
{
    unsigned pc;
    string temp;
    double p;
    getline(is, temp);
    b.setTitle(temp);
    getline(is, temp);
    b.setAuthor(temp);
    is >> pc;
    b.setPageCount(pc);
    is >> p;
    b.setPrice(p);

    if (!is)
    {
        b = Book();
    }
    return is;
}

// output operator
ostream &operator<<(ostream &os, const Book &b)
{
    os << b.title << " " << b.author << " " << b.pageNum << " " << b.price;
    return os;
}

// constructor definition
Book::Book(istream &is)
{
    is >> *this;
}