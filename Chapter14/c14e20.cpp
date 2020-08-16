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
    friend istream &operator>>(istream &, Sales_data &);       // input
    // Arithmetic operators
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend Sales_data operator*(const Sales_data &, int);
    friend Sales_data operator*=(Sales_data &, int);

public:
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    // Sales_data(istream &);
    // remaining constructors all delegate to another constructor
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(string s) : Sales_data(s, 0, 0) {}
    Sales_data(istream &);

    // ADDED: compound addition operator
    Sales_data &operator+=(const Sales_data &);

    // operations on Sales_data objects
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmeber Sales_data interface funtctions
Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);

int main(void)
{
    Sales_data ob1("200-22-1798-X", 20, 10.5);
    Sales_data ob2("200-22-1798-X", 30, 9.5);

    // compound addition test
    cout << "Before ob1 += ob2: " << ob1 << endl;
    ob1 += ob2;
    cout << "After ob1 += ob2: " << ob1 << endl;

    // addition test
    Sales_data sum = ob1 + ob2;
    cout << "ob1 + ob2 result: " << sum << endl;

    // compound multiplication test
    ob2 *= 2;
    cout << "After ob2 *= 2: " << ob2 << endl;

    // multuplication test
    Sales_data result = ob2 * 3;
    cout << "ob2 * 3 result: " << result << endl;
    return 0;
}

// Arithmetic definitions
// compound assignment
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of lhs object
    return *this;                 // return the object on which the function was called
}

// addition, uses += operator
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

// compound multiplication
Sales_data operator*=(Sales_data &lhs, int n)
{
    lhs.units_sold *= n;
    lhs.revenue *= n;
    return lhs;
}

Sales_data operator*(const Sales_data &lhs, int n)
{
    Sales_data result = lhs;
    result *= n;
    return result;
}

// IO definitions
// input operator
istream &operator>>(istream &is, Sales_data &item)
{
    double price; // helper to initialize revenue member
    is >> item.bookNo >> item.units_sold >> price;

    if (is) // check if input succeeded
    {
        item.revenue = item.units_sold * price;
    }
    else // input failed, so give the object the default state
    {
        item = Sales_data();
    }
    return is;
}

// output operator
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
       << " " << item.avg_price();
    return os;
}

// constructor definition
Sales_data::Sales_data(istream &is) : Sales_data::Sales_data()
{
    cin >> *this;
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