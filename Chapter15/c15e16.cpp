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

class BookTransaction : public Disc_quote
{
public:
    // constructor, for simplicity calculates total in its body
    BookTransaction(string isbn, double p, size_t q, double d = 0.1) : Disc_quote(isbn, p, q, d) {}

    // calculate the price
    double net_price(size_t) const;
};

int main(void)
{
    // first ten books have 20% discount
    BookTransaction trans1("87666-100-X-105", 20, 10, .2);
    cout << "First ten books cost " << trans1.net_price(10) << endl;
    cout << "Twenty books cost " << trans1.net_price(20) << endl;
    cout << endl;

    return 0;
}

double BookTransaction::net_price(size_t n) const
{
    // if the client ordered less copies than the limit
    if (n <= quantity)
        return n * price * (1 - discount);
    // calculate discounted and undiscounted total and sum them
    else
        return (n - quantity) * price + (quantity * price * (1 - discount));
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