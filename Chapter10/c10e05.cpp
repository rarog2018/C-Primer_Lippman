#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;
int main(void)
{
    // in previous implementations, it seems that when comparing 2 c-style
    // strings, equal() algorithm was comparing the addresses of the pointers
    // instead of values beneath them, but in october 2019 it compares the
    // actual values, so both rosters are equal
    vector<string> roster3(14, "helloi");
    vector<const char *> roster1{"hello", "world", "!"};
    list<const char *> roster2{"hello", "world", "!"};
    cout << ((equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()))
                 ? "true"
                 : "false")
         << endl;
    return 0;
}