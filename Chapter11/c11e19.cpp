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
    // multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
    multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)>
        bookstore(compareIsbn);
    // auto ms_it = bookstore.begin(); // with auto
    multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)>::iterator
        ms_it = bookstore.begin(); // without auto
    return 0;
}