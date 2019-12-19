#include <iostream>
#include <vector>
#include <algorithm>
#include "src/Sales_item.h"

using namespace std;
void print_vec(vector<Sales_data> v);
int main(void)
{
    // vector that holds Sales_data objects
    vector<Sales_data> books;
    // Sales_data object to read the data
    Sales_data item;
    // until read() function (friend function of Sales_data class) is valid
    while (read(cin, item))
    {
        // add item to the vector
        books.push_back(item);
    }
    cout << "Vector before sorting: \n";
    print_vec(books);

    // use lambda as a predicate
    sort(books.begin(), books.end(),
         [](const Sales_data &ob1, const Sales_data &ob2) { return ob1.isbn() < ob2.isbn(); });
    cout << "Vector after sorting: \n";
    print_vec(books);
    return 0;
}
void print_vec(vector<Sales_data> v)
{
    for (const auto &e : v)
    {
        // print() is a friend function of Sales_data class
        print(cout, e);
        cout << endl;
    }
}
