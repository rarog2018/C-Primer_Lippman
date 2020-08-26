#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

int main(void)
{
    int a, b;
    string operation, response = "y";
    // map operators to library function objects
    map<string, function<int(int, int)>>
        binops = {
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()},
            {"%", modulus<int>()}};

    cout << "Welcome to the simple desk calculator. Supported operators are: "
         << "+, -, *, / and %" << endl;
    cout << "To use the calculator follow the pattern: integer operator integer"
         << endl;

    while (response == "y")
    {
        cout << "Type the computation: ";
        cin >> a >> operation >> b;
        cout << a << " " << operation << " " << b << " = "
             << binops[operation](a, b) << endl;

        cout << "Want to do another computation? (type 'y' if yes) ";
        cin >> response;
        cout << endl;
    }

    // tests
    /*
    a = 22, b = 11;
    cout << a << " + " << b << " = " << binops["+"](a, b) << endl;
    cout << a << " - " << b << " = " << binops["-"](a, b) << endl;
    cout << a << " * " << b << " = " << binops["*"](a, b) << endl;
    cout << a << " / " << b << " = " << binops["/"](a, b) << endl;
    cout << a << " % " << b << " = " << binops["%"](a, b) << endl;
    */
    return 0;
}