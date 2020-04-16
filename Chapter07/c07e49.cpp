#include <iostream>
using namespace std;

class Sales_data
{
    // friend declarations
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    // constructors
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) {}
    Sales_data(istream &is);

    // member functions
    string isbn() const { return bookNo; }

    ///////////////////////////////////////////////////////////////////////////
    // if constructor is not explicit then it will create a temporary Sales_data
    // object using Sales_data(string &) constructor with values (s, 0, 0.0)
    // and copy the values of that temporary object into object on which it's
    // called
    Sales_data &combine(Sales_data);

    // the code won't compile because it is impossible to bind a temporary object
    // and a non-const reference. Non-const reference can only refer to an "lvalue"
    // Sales_data &combine(Sales_data &);

    // the conde won't compile because all the members of the object on which
    // combine() tries to work are const - read-only objects, so no values can be
    // assigned to them
    // Sales_data &combine(const Sales_data &) const;

    // Sales_data &combine(const Sales_data &);

private:
    // inline avg_price()
    inline double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    // old members
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmeber Sales_data interface funtctions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
istream &read(istream &is, Sales_data &obj);
ostream &print(ostream &os, const Sales_data &obj);

////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    const string s("9-999-99999-9");
    Sales_data i(s, 15, 20);

    i.combine(s);
    print(cout, i) << endl;
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
// Sales_data &Sales_data::combine(const Sales_data &rhs)
Sales_data &Sales_data::combine(Sales_data rhs)
// Sales_data &Sales_data::combine(Sales_data &rhs)
// Sales_data &Sales_data::combine(const Sales_data &rhs) const
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