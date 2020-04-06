#include <iostream>
using namespace std;

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
    Sales_data total(cin); // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (cin)
    {
        Sales_data trans(cin); // variable to hold the running sum
        // read and process the remaining transactions
        while (cin)
        {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
            {
                // update the running total
                total.combine(trans);
            }
            else
            {
                // print results for the previous book
                print(cout, total) << endl;
                total = trans; // total now refers to the next book
            }
            read(cin, trans); // new data for trans
        }
        print(cout, total) << endl; // print the last transaction
    }
    else
    {
        // no input! warn the user
        cerr << "No data?!" << endl;
        return -1; // indicate failure
    }

    return 0;
}

// constructor definition
Sales_data::Sales_data(istream &is)
{
    cout << "Using Sales_data(istream *is)" << endl;
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