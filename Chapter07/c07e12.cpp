#include <iostream>
using namespace std;

// the Sales_data(istream &is) constructor won't work properly, because the
// declaration of read() is not known at the time it is executed inside the
// body of the constructor
struct Sales_data; // definition for read() function
// now read() "is known" for the constructor
istream &read(istream &is, Sales_data &obj);

struct Sales_data
{
    // constructors
    // default constructor, behaves as synthesized default constructor
    Sales_data() = default;
    // takes one argument and initializes bookNo with it, others members are
    // in-class initialized with values 0 and 0.0
    Sales_data(string &s) : bookNo(s) { cout << "Using Sales_data(string &s)" << endl; }
    // takes 3 arguments and initializes all class members with the given values
    // revenue member is initialized with the result of price * units_sold
    Sales_data(string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) { cout << "Using Sales_data(string &s, unsigned u, double p)" << endl; }
    // takes one argument which is an istream & from which, using the read()
    // nonmember function, all the members are initialized
    Sales_data(istream &is)
    {
        cout << "Using Sales_data(istream *is)" << endl;
        // reads a transaction from the given stram into the object on which it
        // is called
        read(is, *this);
    }

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
ostream &print(ostream &os, const Sales_data &obj);

int main(void)
{
    string isbn("83-200-X");
    Sales_data book1; // default constructor
    print(cout, book1);

    Sales_data book2(isbn); // Sales_data(string &s)
    print(cout, book2);

    Sales_data book3(isbn, 10, 30); // Sales_data(string &s, unsigned u, double p)
    print(cout, book3);

    Sales_data book4(cin); // Sales_data(istream &is)
    print(cout, book4);

    return 0;
}

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
    os << obj.isbn() << " " << obj.units_sold << " " << obj.revenue << endl;
    return os;
}