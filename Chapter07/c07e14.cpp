#include <iostream>
using namespace std;

struct Sales_data
{
    // constructors
    // default constructor, explicitly initializes the members with the values
    // that would otherwise be used by synthesized default constructor
    Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}
    // takes one argument and initializes bookNo with it, others members are
    // in-class initialized with values 0 and 0.0
    Sales_data(string &s) : bookNo(s) {}
    // takes 3 arguments and initializes all class members with the given values
    // revenue member is initialized with the result of price * units_sold
    Sales_data(string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) {}
    // takes one argument which is an istream & from which, using the read()
    // nonmember function, all the members are initialized
    // the definition is outside the class
    Sales_data(istream &is);

    // exercise 07.02 code
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    // old members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// new nonmeber Sales_data interface funtctions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
istream &read(istream &is, Sales_data &obj);
ostream &print(ostream &os, const Sales_data &obj);

int main(void)
{
    Sales_data book1; // default constructor
    print(cout, book1);

    return 0;
}

// constructor definition
Sales_data::Sales_data(istream &is)
{
    // reads a transaction from the given stram into the object on which it
    // is called
    read(is, *this);
}
///////////////////////////////////////////////////////////////////////////////

// acts like += operator
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of "this" object
    return *this;                 // return the object on which the function was called
}

// adds 2 Sales_data objects and returns their sum
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // initialize sum with 'lhs' object data
    sum.combine(rhs);     // sum += rhs
    return sum;
}

// read the data from the given stream to the given object
istream &read(istream &is, Sales_data &obj)
{
    double price = 0; // book price to compute obj.revenue
    // read the data into object
    is >> obj.bookNo >> obj.units_sold >> price;
    // compute the revenue member
    obj.revenue = price * obj.units_sold;
    return is;
}

// print the contents of the given object on the given stream
ostream &print(ostream &os, const Sales_data &obj)
{
    // print the data from the object
    os << obj.isbn() << " " << obj.units_sold << " " << obj.revenue;
    return os;
}