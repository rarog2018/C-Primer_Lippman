#include <iostream>
#include "Sales_item.h"
using namespace std;
int main(void)
{
    Sales_item book, currBook;
    cout << "Enter Sales_item objects: ";
    // read first book data
    if (cin >> currBook)
    {
        // set count to 1
        int count = 1;
        // read another book data
        while (cin >> book)
        {
            // check if isbns match
            if (currBook.isbn() == book.isbn())
            {
                ++count; // update count
            }
            else
            {
                // print how many times that particular isbn occured
                cout << "Isbn " << currBook.isbn() << " occurs " << count
                     << " times." << endl;
                currBook = book; // update currBook
                count = 1;       // reset count
            }
        }
        // print how many times the last isbn occured
        cout << "Isbn " << currBook.isbn() << " occurs " << count
             << " times." << endl;
    }
    return 0;
}