#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Sales_data
{
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &is, Sales_data &item);
    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    // Sales_data(std::istream &);
    // remaining constructors all delegate to another constructor
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
    }

    // assignment operators
    Sales_data &operator+=(const Sales_data &);

    std::string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmeber Sales_data interface funtctions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

template <typename T>
int compare(const T &, const T &); // declaration

int main(void)
{
    Sales_data ob1("987-055-22-X", 10, 20), ob2("987-333-11-5", 10, 30);

    // Sales_data does not have < operator
    cout << compare(ob1, ob2) << endl;

    // errors:
    // error: no match for 'operator<'
    return 0;
}

template <typename T>
int compare(const T &v1, const T &v2) // definition
{
    if (less<T>()(v1, v2))
        return -1;
    if (less<T>()(v2, v1))
        return 1;
    return 0;
}

// SALES DATA
// member binary operator: left-hand operand is bound to the implicit this pointer
// assumes that both objects refer to the same book
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// assumes that both objects refer to the same book
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum += rhs;           // add rhs into sum
    return sum;
}

// equality operator
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}
// inequality operator
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

// input operator
std::istream &operator>>(std::istream &is, Sales_data &item)
{
    double price; // no need to initialize; we'll read into price before we use it
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // check that the inputs succeeded
        item.revenue = item.units_sold * price;
    else
        item = Sales_data(); // input failed: give the object the default state
    return is;
}

// output operator
std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
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
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
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