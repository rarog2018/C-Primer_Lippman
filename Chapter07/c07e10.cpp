#include <iostream>
using namespace std;

struct Sales_data
{
    // exercise 07.02 code
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    // old members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// new nonmeber Sales_data interface funtctions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
istream &read(istream &is, Sales_data &obj);
ostream &print(ostream &os, const Sales_data &obj);

int main(void)
{
    ///////////  WHAT DOES THIS CONDITION DO    ///////////////////
    Sales_data data1, data2;
    // read() returns istream object, so the first call to read calls
    // read(cin, data1) and evaluates the data validity depending on
    // the state of returned istream object
    // if we tried to fill data1 with incorrect data the condition will
    // fail and we won't proceed to read data2
    // if we read correct data for data1 object and incorrect for data2
    // then the condition is false and the code inside if statement
    // won't be executed
    if (read(read(cin, data1), data2))
    {
        print(cout, data2);
    }
    else
    {
        cout << "Incorrect data" << endl;
    }

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
    os << obj.isbn() << " " << obj.units_sold << " " << obj.revenue;
    return os;
}