#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void)
{
    // the only problem with that is that the third value is a price not a revenue
    // Sales_data item = {"978-0590353403", 25, 15.99};
    // we can fix it by providing an appropriate expression
    Sales_data item = {"978-0590353403", 25, 15.99 * 25};
    cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
    return 0;
}