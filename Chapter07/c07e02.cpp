#include <iostream>
using namespace std;

struct Sales_data
{
    // new members: operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    // old members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main(void)
{
    return 0;
}

// acts like += operator
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of "this" object
    return *this;                 // return the object on which the function was called
}