#include <iostream>
using namespace std;

class SmallInt
{
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }                                    // conversion from int
    operator int() const { return val; } // conversion to int
    size_t get_val() const { return val; }

private:
    std::size_t val;
};

struct LongDouble
{
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt &);

    LongDouble(double v = 0.0) : val(v) { cout << "using LongDouble constructor" << endl; }
    operator double();
    // operator float();

    long double val;
};

LongDouble operator+(LongDouble &, double);
SmallInt operator+(const SmallInt &, const SmallInt &);

int main(void)
{
    SmallInt si(3);
    LongDouble ld(17.35);

    // first problem here is that there is more than one possible conversion
    // from LongDouble to the built-in type: operator double() and operator float()
    // but if we comment one of the conversion operators, the sequence is:
    // si gets promoted to int and converted to double,
    // ld gets converted to double using operator double()
    // the result which has type double is then converted to LongDouble using
    // the LongDouble constructor
    cout << "si + ld = " << endl;
    ld = si + ld;
    cout << ld.val << endl;

    // here, because the addition is LongDouble + SmallInt the overloaded
    // LongDouble operator+(const SmallInt &); will be used for this addition
    // although it all depends how we define LongDouble operator+
    cout << "\nld + si = " << endl;
    ld = ld + si;
    cout << ld.val << endl;
    return 0;
}

// addition operators
SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
    cout << "Using: SmallInt operator+(const SmallInt &, const SmallInt &)" << endl;
    SmallInt sum = lhs;
    sum = sum + rhs;
    return sum;
}

LongDouble LongDouble::operator+(const SmallInt &rhs)
{
    cout << "Using: LongDouble operator+(const SmallInt &)" << endl;
    val = val + rhs.get_val(); // this is not ambiguous
    // val = val + rhs; // this is ambiguous it can use also SmallInt operator+(SI, SI)
    return *this;
}

// conversion operators
LongDouble::operator double()
{
    cout << "using: operator double()" << endl;
    return static_cast<double>(val);
}