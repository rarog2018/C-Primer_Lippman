#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
    // MODIFIED: constructors
    // Quote() = default;
    Quote() { cout << "Using Quote::Quote() default constructor" << endl; }
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price)
    {
        cout << "Using Quote::Quote(const string &, double) constructor" << endl;
    }

    // ADDED: other copy control members
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

    // dectructor
    // virtual ~Quote() = default; // dynamic binding for the destructor
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
// MODIFIED
class Bulk_quote : public Disc_quote // now inherits from Disc_quote
{
public:
    // MODIFIED: constructors
    // Bulk_quote() = default;
    Bulk_quote() { cout << "Using Bulk_quote::Bulk_quote() default constructor" << endl; }

    Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
        cout << "Using Bulk_quote::Bulk_quote(const string&, double, size_t, double) constructor" << endl;
    } // now uses Disc_quote constructor

    // ADDED: other copy control members
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
    cout << "Beginning of the program" << endl;
    /*
    cout << "\nDefining: Quote item('97-88888-X-200', 50)..." << endl;
    Quote item("97-88888-X-200", 50);
    item.debug(cout);

    cout << "\nDefining: Quote item2..." << endl;
    Quote item2;
    item2.debug(cout);

    cout << "\nDefining: Quote item3(item)..." << endl;
    Quote item3(item);
    item3.debug(cout);

    cout << "\nAssigning: item2 = item3..." << endl;
    item2 = item3;
    item2.debug(cout);

    cout << "\nDefining: Quote item4(std::move(item))..." << endl;
    Quote item4(std::move(item));
    item4.debug(cout);

    cout << "\nAssigning: item2 = item4..." << endl;
    item2 = std::move(item4);
    item2.debug(cout);
    */

    cout << "\nDefining: Bulk_quote bitem..." << endl;
    Bulk_quote bitem;
    bitem.debug(cout);

    cout << "\nDefining: Bulk_quote bitem1('9778-X-205', 35.5, 10, 0.1)..." << endl;
    Bulk_quote bitem1("9778-X-205", 35.5, 10, 0.1);
    bitem1.debug(cout);

    cout << "\nDefining: Bulk_quote bitem2(bitem1)..." << endl;
    Bulk_quote bitem2(bitem1);
    bitem2.debug(cout);

    cout << "\nDefining: Bulk_quote bitem3(std::move(bitem1))..." << endl;
    Bulk_quote bitem3(std::move(bitem1));
    bitem3.debug(cout);

    cout << "\nAssigning: bitem = bitem2..." << endl;
    bitem = bitem2;
    bitem.debug(cout);

    cout << "\nAssigning: bitem = bitem3..." << endl;
    bitem = std::move(bitem3);
    bitem.debug(cout);

    cout << "\nEnd of the program" << endl;
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