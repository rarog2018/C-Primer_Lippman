#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
    // friend declarations
    friend ostream &operator<<(ostream &, const Book &); // output operator
    friend istream &operator>>(istream &, Book &); // input operator

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
    cout << b1 << endl;

    Book b2;
    cin >> b2;
    cout << endl;
    cout << b2 << endl;
    return 0;
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