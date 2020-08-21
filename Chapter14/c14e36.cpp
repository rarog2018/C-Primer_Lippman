#include <iostream>
#include <string>
#include <vector>
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
    vector<string> svec;
    PrintString prntr;
    string temp;

    // its scarry that this is the first thing that came to my mind
    while (!(temp = prntr()).empty())
        svec.push_back(temp);

    for (auto &e : svec)
        cout << e << endl;
    return 0;
}