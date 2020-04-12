#include <iostream>
using namespace std;

class Sales_data
{
    // friend declarations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    // constructors
    // Sales_data() = default;
    Sales_data(string &s) : bookNo(s) {} // uncommented to not have 2 def constr.

    // equivalent to the two above
    // Sales_data(std::string s = "") : bookNo(s) {}

    Sales_data(string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) {}
    // Sales_data(istream &is);

    /////////////////////////////////////////////////////////////////////////////
    // constructor that uses cin as a default argument, now becomes the default constr.
    Sales_data(istream &is = cin);

    // member functions
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

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
Sales_data first_item; // using Sales_data(istream &is)

int main(void)
{
    Sales_data next; // using the default constructor,which is Sales_data(istream &is)
    // Sales_data last("9-999-99999-9"); // using the default constructor

    print(cout, first_item) << endl;
    print(cout, next) << endl;
    // print(cout, last) << endl;

    return 0;
}

// constructor definition
Sales_data::Sales_data(istream &is)
{
    cout << "Sd(istream &is)\n";
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