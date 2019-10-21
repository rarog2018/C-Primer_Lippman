#include <iostream>
#include <string>

using namespace std;
string add_pref_suf(string name, const string &prefix, const string &suffix);
int main(void)
{
    string name = "Frederic", prefix = "Mr. ", suffix = "III";
    cout << name << endl;
    string newName(add_pref_suf(name, prefix, suffix));
    cout << newName << endl;
    return 0;
}
string add_pref_suf(string name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    name.append(" " + suffix);
    return name;
}