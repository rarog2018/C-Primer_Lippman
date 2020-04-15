#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    // constructor to which we delegate
    Book(unsigned nop, const string &t, const string &a, double p) : pageNum(nop), title(t), author(a), price(p) {}
    // default constructor
    Book() : Book(0, "", "", 0) {}
    Book(string &t, string &a) : Book(0, t, a, 0) {}

private:
    unsigned pageNum = 0;
    string title;
    string author;
    double price = 10.0;
};

int main(void)
{
    return 0;
}
