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
    // print the members
    virtual void debug(ostream &) const;

    // dectructor
    virtual ~Quote() = default; // dynamic binding for the destructor

private:
    string bookNo; // ISBN number of this item

protected:
    double price = 0.0; // normal, undiscounted price
};

// Bulk_quote class
class Bulk_quote : public Quote // Bulk_quote inherits from Quote
{
public:
    // constructors
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

    // methods
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(size_t) const override;
    // override the printing from the base class
    void debug(ostream &) const override;

private:
    size_t min_qty = 0;    // minimum purchase for the discount to apply
    double discount = 0.0; // fractional discount to apply
};

double print_total(ostream &, const Quote &, size_t);

int main(void)
{
    Quote item("97-88888-X-200", 50);
    // object with isbn, that costs 50 units, and can be sold with the discount
    // when someone buys at least 10 copies, the discount is 20%
    Bulk_quote item2("98-77777-Y-105", 50, 10, 0.20);

    // print members
    item.debug(cout);
    item2.debug(cout);

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
void Quote::debug(ostream &os) const
{
    os << bookNo << " " << price << endl;
}

inline string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(size_t n) const
{
    return price * n;
}

// Bulk_quote methods definitions
void Bulk_quote::debug(ostream &os) const
{
    os << isbn() << " " << price << " " << min_qty << " " << discount << endl;
}
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}