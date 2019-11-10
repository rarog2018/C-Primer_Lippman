#include <iostream>
#include <string>

using namespace std;
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
int main(void)
{
    string a = "hello", b = "world!";
    cout << "First string is shorter than second: ";
    cout << (isShorter(a, b) ? "true" : "false") << endl;
    return 0;
}
