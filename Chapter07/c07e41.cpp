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
    // constructor to which we delegate
    Sales_data(const string &s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p * u) { cout << "Constructor to which one delegates\n"; }
    // default contructor
    Sales_data() : Sales_data("", 0, 0) { cout << "Default constructor\n"; }
    Sales_data(string s) : Sales_data(s, 0, 0) { cout << "Single string constructor\n"; }
    Sales_data(istream &is) : Sales_data()
    {
        cout << "Istream constructor\n";
        read(is, *this);
    }

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

int main(void)
{
    // The messages are printed sort of in the reverse order, because the body
    // of the constructor is executed last, so when the constructor delegates
    // to another constructor, the delegated-to constructor executes first its
    // task and code inside its body, then we get back to our initial constructor's
    // function body
    cout << "First object: " << endl;
    Sales_data item1;
    cout << endl;

    cout << "Second object: " << endl;
    Sales_data item2("hello");
    cout << endl;

    cout << "Third object: " << endl;
    Sales_data item3("hello", 15, 17.99);
    cout << endl;

    cout << "Fourth object: " << endl;
    Sales_data item4(cin);
    cout << endl;
    return 0;
}

/*// constructor definition
Sales_data::Sales_data(istream &is)
{
    cout << "Sd(istream &is)\n";
    // reads a transaction from the given stram into the object on which it
    // is called
    read(is, *this);
}*/
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