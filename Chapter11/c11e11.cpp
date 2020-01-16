#include <iostream>
#include <set>
#include "src/Sales_item.h"
using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
int main(void)
{
    Sales_data book1{"0-200-X 10 20"}, book2{"0-201-X 10 30"}, book3{"0-200-Y 5 50"},
        book4{"0-200-X 5 10"}, book5{"0-201-X 20 40"};
    // using decltype
    // multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    // without decltype
    multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)>
        bookstore(compareIsbn);

    bookstore = {book1, book2, book3, book4, book5};
    cout << endl;
    for (const auto &b : bookstore)
    {
        cout << b.isbn() << endl;
    }
    return 0;
}