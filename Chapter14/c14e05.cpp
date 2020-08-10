#include <iostream>
#include <vector>
#include <string>
using namespace std;

// it should have for sure IO operators and assignment operator

class Book
{
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

// output operator
ostream &operator<<(ostream &os, const Book &b)
{
    os << "Title: " << b.getTitle() << ", Author: " << b.getAuthor()
       << "\nPage count: " << b.getPageCount() << ", Price: "
       << b.getPrice() << " PLN" << endl;
    return os;
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
    return is;
}

Book::Book(istream &is)
{
    is >> *this;
}
int main(void)
{
    Book b1(350, "Witcher", "Sapkowski", 25);
    cout << b1;

    vector<Book> bvec;
    while (true)
    {
        Book temp(cin);
        bvec.push_back(temp);
        cin.get();
        if (!cin)
            break;
    }

    for (auto &e : bvec)
    {
        cout << e << endl;
    }
    return 0;
}
