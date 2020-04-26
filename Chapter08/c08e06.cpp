#include <iostream>
#include <fstream>
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
    explicit Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) {}
    Sales_data(istream &is);

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

int main(int argc, char *argv[])
{
    // construct an ifstream object that'll read the given file
    ifstream ifs(argv[1]);
    if (ifs)
    {
        Sales_data total; // variable to hold the running sum
        if (read(ifs, total))
        {                     // read the first transaction
            Sales_data trans; // variable to hold data for the next transaction
            while (read(ifs, trans))
            {                                     // read the remaining transactions
                if (total.isbn() == trans.isbn()) // check the isbns
                    total.combine(trans);         // update the running total
                else
                {
                    print(cout, total) << endl; // print the results
                    total = trans;              // process the next book
                }
            }
            print(cout, total) << endl; // print the last transaction
        }
        else
        {                                // there was no input
            cerr << "No data?!" << endl; // notify the user
        }
    }

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