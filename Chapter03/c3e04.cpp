#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;

    // compare the strings
    if (s1 == s2)
    {
        cout << "Strings s1 and s2  are equal" << endl;
    }
    else if (s1 > s2)
    {
        cout << "s1 is greater than s2" << endl;
    }
    else
    {
        cout << "s2 is greater than s1" << endl;
    }

    // compare length
    if (s1.length() == s2.length())
    {
        cout << "Strings s1 and s2 have equal length" << endl;
    }
    else if (s1.length() > s2.length())
    {
        cout << "s1 has more characters than s2" << endl;
    }
    else
    {
        cout << "s2 has more characters than s1" << endl;
    }
    return 0;
}