#include <iostream>
using namespace std;

class BookTransaction
{
public:
    // constructor, for simplicity calculates total in its body
    BookTransaction(unsigned i, size_t n, double p, double d = 0.1, size_t l = 3) : id(i), numCopies(n), price(p), discount(d), limit(l) { total = net_price(); }

    // calculate the price
    double net_price() const;
    // get total
    double get_total() const { return total; }

private:
    unsigned id;      // book id
    size_t numCopies; // number of copies in transaction
    double price;     // price of each copy
    double discount;  // discount
    size_t limit;     // limit of copies to which the discount applies
    double total;     // total price of the transaction
};

int main(void)
{
    // order 1 copy of book with id 333 that costs 20 units
    BookTransaction trans1(333, 1, 20);
    // order 5 copies of the same book with the same price
    BookTransaction trans2(333, 5, 20);
    cout << "Total price of trans1: " << trans1.get_total() << endl;
    cout << "Total price of trans2: " << trans2.get_total() << endl;
    cout << endl;

    // lets repeat the above but with additional members specified
    // order 1 copy of book with id 333 that costs 20 units, 50% discount!
    BookTransaction trans3(333, 2, 20, 0.5, 5);
    // order 5 copies of the same book with the same price
    BookTransaction trans4(333, 10, 20, 0.5, 5);
    cout << "Total price of trans3: " << trans3.get_total() << endl;
    cout << "Total price of trans4: " << trans4.get_total() << endl;
    return 0;
}

double BookTransaction::net_price() const
{
    // if the client ordered less copies than the limit
    if (numCopies <= limit)
        return numCopies * price * (1 - discount);
    // calculate discounted and undiscounted total and sum them
    else
        return (numCopies - limit) * price + (limit * price * (1 - discount));
}