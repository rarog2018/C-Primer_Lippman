#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    Book(string s = "", string as = "") : title(s), author(as) {}
    Book(unsigned nop, string &t, string &a, double p) : pageNum(nop), title(t), author(a), price(p) {}

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
