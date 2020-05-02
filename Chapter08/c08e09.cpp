#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

istream &fnc(istream &is);

int main(void)
{
    string line;
    ifstream iF("abc.txt"); // read contents of the file to ifstream
    if (iF.is_open())
    {
        while (getline(iF, line)) // store each line in a string
        {
            istringstream isS(line); // bind iss to the line
            fnc(isS);                // use the function from c08e01 to print isS contents
        }
    }

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