#include <iostream>
using namespace std;

// Function template - definition from which specific functions can be instantiated
// Class template - definition from which specific classes can be instantiated
// for example

// Function template
template <typename T>
void hello(const T &arg)
{
    cout << "Hello " << arg << endl;
}

// Class template
template <typename T>
class HellNo
{
public:
    HellNo() = default;

    void hello(const T &arg) const
    {
        cout << "No hello for " << arg << endl;
    }
};

int main(void)
{
    // uses function template above to instantiate:
    // void hello<char [10]> hello(const char (&arg)[10])
    hello("Stregobor");
    // void hello<int> hello(const int &arg)
    hello(15);

    // uses class template aboce to instantiate:
    // HellNo<double>
    HellNo<double> obd;
    // instantiates void HellNo<double>::hello(const double &arg) const
    obd.hello(17.7);
    return 0;
}