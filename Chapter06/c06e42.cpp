#include <iostream>

using namespace std;
string make_plural(size_t ctr, const string &word, const string &ending = "s");
int main(void)
{
    cout << make_plural(1, "player") << endl;
    cout << make_plural(2, "player") << endl;
    return 0;
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}