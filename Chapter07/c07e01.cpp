#include <iostream>
#include "src/c02Sales_data.h"

int main(void)
{
    double price;     // variable to hold the price
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total.isbn >> total.unitsSold >> price)
    {
        // calculate revenue
        total.revenue = total.unitsSold * price;
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.isbn >> trans.unitsSold >> price)
        {
            trans.revenue = trans.unitsSold * price;
            // if we're still processing the same book
            if (total.isbn == trans.isbn)
            {
                // update the running total
                total.unitsSold += trans.unitsSold;
                total.revenue += trans.revenue;
            }
            else
            {
                // print results for the previous book
                std::cout << total.isbn << " " << total.unitsSold << " "
                          << total.revenue << std::endl;
                total = trans; // total now refers to the next book
            }
        }
        std::cout << total.isbn << " " << total.unitsSold << " "
                  << total.revenue << std::endl; // print the last transaction
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    return 0;
}