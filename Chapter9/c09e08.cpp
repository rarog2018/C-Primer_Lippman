#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
    list<string> slst{"HI", "Hello", "World is big", "ESP LTD Guitar"};
    // same size as list above
    list<string> slst2(slst.size());

    // type to read list of strings
    list<string>::const_iterator citer;
    // type to write to the list of strings
    list<string>::iterator w_r_iter;

    // in action
    for(citer = slst.cbegin(), w_r_iter = slst2.begin(); citer != slst.cend(); ++citer, ++w_r_iter)
        *w_r_iter = *citer;

    for(const auto e : slst2)
        cout << e << endl;

}
