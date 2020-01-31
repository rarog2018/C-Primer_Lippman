#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    string isbn;
    unsigned unitsSold = 0;
    double revenue = 0.0;
};
int main(void)
{
    Sales_data book1, book2;
    double price = 0;
    /*
    //////////////////////          e01.20          //////////////////////////
    // read the data
    cout << "Enter book1 data: ";
    cin >> book1.isbn >> book1.unitsSold >> price;
    book1.revenue = price * book1.unitsSold; // calculate revenue
    cout << "Enter book2 data: ";
    cin >> book2.isbn >> book2.unitsSold >> price;
    book2.revenue = price * book2.unitsSold; // revenue

    // print the data
    cout << "\nBook1: " << book1.isbn << " " << book1.revenue << " "
         << book1.unitsSold << endl;
    cout << "Book2: " << book2.isbn << " " << book2.revenue << " "
         << book2.unitsSold << endl;

    //////////////////////          e01.21          //////////////////////////
    // if isbns are identical print the sum if not print error message
    if (book1.isbn == book2.isbn)
    {
        cout << "Total revenue: " << book1.revenue + book2.revenue << endl;
        cout << "Copies sold: " << book1.unitsSold + book2.unitsSold << endl;
    }
    else
    {
        cerr << "ISBNs must be identical." << endl;
    }
    */
    /*
    //////////////////////          e01.24          //////////////////////////
    Sales_data book, currBook;
    cout << "Enter Sales_item objects: ";
    // read first book data
    if (cin >> currBook.isbn >> currBook.unitsSold >> price)
    {
        currBook.revenue = price * currBook.unitsSold;
        // set count to 1
        int count = 1;
        // read another book data
        while (cin >> book.isbn >> book.unitsSold >> price)
        {
            book.revenue = price * book.unitsSold;
            // check if isbns match
            if (currBook.isbn == book.isbn)
            {
                ++count; // update count
            }
            else
            {
                // print how many times that particular isbn occured
                cout << "Isbn " << currBook.isbn << " occurs " << count
                     << " times." << endl;
                currBook = book; // update currBook
                count = 1;       // reset count
            }
        }
        // print how many times the last isbn occured
        cout << "Isbn " << currBook.isbn << " occurs " << count
             << " times." << endl;
    }
    */
    //////////////////////          e01.25          //////////////////////////
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total.isbn >> total.unitsSold >> price)
    {
        total.revenue = price * total.unitsSold;
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.isbn >> trans.unitsSold >> price)
        {
            trans.revenue = price * trans.unitsSold;
            // if we're still processing the same book
            if (total.isbn == trans.isbn)
            {
                total.revenue += trans.revenue; // update the running total
                total.unitsSold += trans.unitsSold;
            }
            else
            {
                // print results for the previous book
                std::cout << total.isbn << " " << total.revenue << " "
                          << total.unitsSold << " "
                          << total.revenue / total.unitsSold << std::endl;
                total = trans; // total now refers to the next book
            }
        }
        // print the last transaction
        std::cout << total.isbn << " " << total.revenue << " "
                  << total.unitsSold << " "
                  << total.revenue / total.unitsSold << std::endl;
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    return 0;
}