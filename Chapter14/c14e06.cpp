#include <iostream>
using namespace std;

class Sales_data
{
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);
    // IO overloaded operators
    friend ostream &operator<<(ostream &, const Sales_data &); // output

public: // access specifier added
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    // Sales_data(istream &);
    // remaining constructors all delegate to another constructor
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(string s) : Sales_data(s, 0, 0) {}
    Sales_data(istream &is) : Sales_data()
    {
        read(is, *this);
    }

    // new members: operations on Sales_data objects
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

    // ADDED: overloaded operators declarations
    // all of them (except compound-addition) should be declaret OUTSIDE of the
    // class
    // compound addition
    Sales_data &operator+=(const Sales_data &);

private: // access specifier added
    double avg_price() const;
    // old members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// NEW overloaded operators declarations
// input
istream &operator>>(istream &, Sales_data &);
// output
ostream &operator<<(ostream &, const Sales_data &);
// regular addition
Sales_data operator+(const Sales_data &, const Sales_data &);

// nonmeber Sales_data interface funtctions
Sales_data
add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);

int main(void)
{
    return 0;
}

// IO definitions
// output operator
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
       << " " << item.avg_price();
    return os;
}

// constructor definition
Sales_data::Sales_data(istream &is)
{
    read(is, *this); // read will read a transaction from is into this object
}

//////////////////////////////////////
double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

// it is supposed to act like += operator
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of "this" object
    return *this;                 // return the object on which the function was called
}

// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);     // add data members from rhs into sum
    return sum;
}