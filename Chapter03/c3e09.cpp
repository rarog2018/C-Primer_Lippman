#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // the program tries to print the first character of string 's'
    // the string 's' is an empty string, so the result is undefined, because
    // it tries to reach an out of range character
    string s;
    cout << s[0] << endl;
    return 0;
}