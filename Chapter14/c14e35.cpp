#include <iostream>
#include <string>
using namespace std;

class PrintString
{
public:
    // constructor
    PrintString(istream &i = cin) : is(i) {}

    // call operator
    string operator()()
    {
        string line;
        getline(is, line);
        return is ? line : "";
    }

private:
    istream &is;
};

int main(void)
{
    PrintString prntr;
    cout << prntr() << endl;
    return 0;
}