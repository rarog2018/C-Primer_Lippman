#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void compare_strings(string s1, string s2);
void compare_cstyle_string(const char cs1[], const char cs2[]);
int main()
{
    string s1{"Hello world!"}, s2{"Endl"};
    compare_strings(s1, s2);
    const char cs1[] = {'E', 'n', 'd', 'l', '\0'};
    const char cs2[] = {'h', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    compare_cstyle_string(cs1, cs2);
    return 0;
}

void compare_strings(string s1, string s2)
{
    if (s1 == s2)
        cout << "S1 and S2 are equal.\n";
    else if (s1 > s2)
        cout << "S1 is greater than S2.\n";
    else
        cout << "S2 is greater than S1.\n";
}

void compare_cstyle_string(const char cs1[], const char cs2[])
{
    int a = strcmp(cs1, cs2);
    if(a == 0)
        cout << "CS1 and CS2 are equal.\n";
    else if (a == 1)
        cout << "CS1 is greater than CS2.\n";
    else
        cout << "CS2 is greater than CS1.\n";
}
