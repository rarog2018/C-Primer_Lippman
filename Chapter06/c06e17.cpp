#include <iostream>
#include <string>

using namespace std;
bool has_capital_letters(const string &s);
void to_lowercase(string &s);
// i did not use the same parameter's type because in first function i do not
// want to change the original string, so the parameter should be const,
// and in the second string the change is necessary, so the parameter cannot
// be const, although it was possble to use the same parameters in both functions
// but it would be less effective
int main(void)
{
    string word{"hello WORLD"};
    cout << (has_capital_letters(word) ? "true" : "false") << endl;
    to_lowercase(word);
    cout << word << endl;
    return 0;
}

bool has_capital_letters(const string &s)
{
    for (auto &e : s)
    {
        if (e >= 'A' && e <= 'Z')
        {
            return true;
        }
    }
    return false;
}

void to_lowercase(string &s)
{
    for (auto &e : s)
    {
        if (e >= 'A' && e <= 'Z')
        {
            e += 32;
        }
    }
}