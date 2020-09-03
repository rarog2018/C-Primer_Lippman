#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
    // constructors
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}

    // member functions
    string isbn() const;
    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(size_t n) const;

    // dectructor
    virtual ~Quote() = default; // dynamic binding for the destructor

private:
    string bookNo; // ISBN number of this item

protected:
    double price = 0.0; // normal, undiscounted price
};

double print_total(std::ostream &, const Quote &, std::size_t);

int main(void)
{
    Quote item("97-88888-X-200", 55.99);
    // calculate the price of 15 copies
    double total = print_total(cout, item, 15);
    cout << "Confirm the result: " << total << endl;
    return 0;
}

// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

// Quote methods definitions
inline string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(size_t n) const
{
    return price * n;
}