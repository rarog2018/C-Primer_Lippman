#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include <iterator>
#include "Sales_item.h"
using namespace std;
using namespace std::placeholders;
bool compareIsbn2(const Sales_item &ob1, const Sales_item &ob2);
int main(void)
{
    Sales_item total;
    // istream iterator bound to cin, that reads Sales_item objects
    istream_iterator<Sales_item> siii(cin), eof;
    // ostream iterator bound to cout, that writes Sales_item objects followed
    // by new line
    ostream_iterator<Sales_item> sioi(cout, "\n");
    // vector that stores Sales_item objects initialized from iterator range
    vector<Sales_item> bookstore(siii, eof);

    // sort the contents of bookstore vector
    sort(bookstore.begin(), bookstore.end(), compareIsbn2);

    // loop through sorted vector
    for (auto first = bookstore.cbegin(), it = first; first != bookstore.cend(); first = it)
    {
        // returns the first element to which the predicate returns a nonzero value
        // so in our case find_if goes through every element in the vector which
        // is a Sales_item object, each becomes temporarily a 'temp' variable
        // and we compare isbns of every element with the element that iterator
        // 'first' is bound to
        // when the two isbns are different lambda returns true and find_if
        // returns the iterator for which lambda returned true
        // this is stored in the 'it' iterator
        it = find_if(first, bookstore.cend(), [first](const Sales_item &temp) { return temp.isbn() != first->isbn(); });
        // every element from first up to but not including it has the same isbn
        // so we accumulate them using accumulate algorithm
        // ostream_iterator prints the value returned by accumulate
        sioi = accumulate(first, it, Sales_item(first->isbn()));
    }
    // copy(bookstore.begin(), bookstore.end(), sioi);
    /*
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total)
    {
        Sales_item trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans)
        {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total += trans; // update the running total
            else
            {
                // print results for the previous book
                std::cout << total << std::endl;
                total = trans; // total now refers to the next book
            }
        }
        std::cout << total << std::endl; // print the last transaction
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }*/
    return 0;
}
bool compareIsbn2(const Sales_item &ob1, const Sales_item &ob2)
{
    // simply combine the isbn strings fetched by member of Sales_data isbn()
    return ob1.isbn() < ob2.isbn();
}
