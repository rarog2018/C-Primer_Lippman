#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Quote
{
public:
    // constructors
    Quote() { cout << "Using Quote::Quote() default constructor" << endl; }
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price)
    {
        cout << "Using Quote::Quote(const string &, double) constructor" << endl;
    }

    // other copy control members
    // copy and move constructors
    Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
    {
        cout << "Using Quote::Quote(const Quote &) copy constructor" << endl;
    }
    Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
    {
        cout << "Using Quote::Quote(Quote &&) move constructor" << endl;
    }

    // copy and move assignment
    Quote &operator=(const Quote &);
    Quote &operator=(Quote &&);

    // member functions
    string isbn() const;
    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(size_t n) const;
    // print the members
    virtual void debug(ostream &) const;

    // dectructor // dynamic binding for the destructor
    virtual ~Quote() { cout << "Using Quote::~Quote() default destructor" << endl; }

private:
    string bookNo; // ISBN number of this item

protected:
    double price = 0.0; // normal, undiscounted price
};

// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote
{
public:
    // constructors
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}

    // methods
    double net_price(std::size_t) const = 0; // pure virtual function

protected:
    std::size_t quantity = 0; // purchase size for the discount to apply
    double discount = 0.0;    // fractional discount to apply
};

// Bulk_quote class
class Bulk_quote : public Disc_quote // now inherits from Disc_quote
{
public:
    // constructors
    Bulk_quote() { cout << "Using Bulk_quote::Bulk_quote() default constructor" << endl; }

    // "inherited" constructors from Disc_quote
    using Disc_quote::Disc_quote;

    // other copy control members
    // copy and move constructors
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs)
    {
        cout << "Using Bulk_quote(const Bulk_quote &rhs) copy constructor" << endl;
    }
    Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs))
    {
        cout << "Using Bulk_quote(Bulk_quote &&rhs) move constructor" << endl;
    }

    // copy and move assignment
    Bulk_quote &operator=(const Bulk_quote &);
    Bulk_quote &operator=(Bulk_quote &&);

    // destructor
    ~Bulk_quote() { cout << "Using ~Bulk_quote() destructor" << endl; }
    // methods
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(size_t) const override;
    // override the printing from the base class
    void debug(ostream &) const override;
};

double print_total(ostream &, const Quote &, size_t);

int main(void)
{
    vector<Quote> basket{Bulk_quote("98777-X-200", 40, 10, 0.1), Bulk_quote("87666-Y-100", 20, 10, 0.2)};

    double sum = 0;
    for (auto &e : basket)
    {
        sum += e.net_price(20);
    }

    cout << endl;
    cout << "Total price: " << sum << endl;
    cout << endl;
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
// copy and move assignment
Quote &Quote::operator=(const Quote &rhs)
{
    cout << "Using &Quote::operator=(const Quote &) copy assignment" << endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote &Quote::operator=(Quote &&rhs)
{
    cout << "Using &Quote::operator=(Quote &&) move assignment" << endl;
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
}

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
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    cout << "Using Bulk_quote::operator=(const Bulk_quote &) copy assignment" << endl;
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)
{
    cout << "Using Bulk_quote::operator=(Bulk_quote &&) move assignment" << endl;
    Quote::operator=(std::move(rhs));
    quantity = std::move(rhs.quantity);
    discount = std::move(rhs.discount);
    return *this;
}

void Bulk_quote::debug(ostream &os) const
{
    os << isbn() << " " << price << " " << quantity << " " << discount << endl;
}
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}