#ifndef SALES_ITEM_H
#define SALES_ITEM_H

class Sales_data {
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    public:
    // nondelegating constructor initializes members from corresponding arguments
        Sales_data(std::string s, unsigned cnt, double price):
                bookNo(s), units_sold(cnt), revenue(cnt*price) { std::cout << "I am a regular constructor\n";}
    // remaining constructors all delegate to another constructor
        Sales_data(): Sales_data("", 0, 0) { std::cout << "I am a default contructor\n";}
        Sales_data(std::string s): Sales_data(s, 0,0) { std::cout << "I am a string constuctor\n";}
        Sales_data(std::istream &is): Sales_data() { std::cout << "I am an istream constructor\n"; read(is, *this); }
    // new members: operations on Sales_data objects
        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);
    private:
        double avg_price() const
            { return units_sold ? revenue/units_sold : 0; }
    // data members are unchanged from § 2.6.1 (p. 72)
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream& is, Sales_data& item);

#endif // SALES_ITEM_H
