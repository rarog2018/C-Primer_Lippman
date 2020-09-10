#include <iostream>
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
    // print the members
    // virtual void debug(ostream &) const;

    // dectructor
    virtual ~Quote() = default; // dynamic binding for the destructor

private:
    string bookNo; // ISBN number of this item

protected:
    double price = 0.0; // normal, undiscounted price
};

class Disc_quote : public Quote
{
public:
    // constructors
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}

    // methods
    double net_price(size_t) const = 0; // pure virtual function

protected:
    size_t quantity = 0;   // purchase size for the discount to apply
    double discount = 0.0; // fractional discount to apply
};

int main(void)
{
    // error: cannot declare variable 'ob' to be of abstract type 'Disc_quote'
    // note:   because the following virtual functions are pure within 'Disc_quote'
    // Disc_quote ob("87666-100-X-101", 20, 10, 0.1);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// methods
inline string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(size_t cnt) const
{
    return price * cnt;
}