#include <iostream>
#include <string>
using namespace std;

istream &fnc(istream &is);

int main(void)
{
    return 0;
}

istream &fnc(istream &is)
{
    string word;
    while (true)
    {
        is >> word;
        if (is.eof())
        {
            break;
        }
        else
        {
            cout << word << endl;
        }
    }
    is.clear();
    return is;
}