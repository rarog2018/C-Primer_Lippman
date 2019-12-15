#include <iostream>
#include <string>

using namespace std;
// it would not be possible to define isShorter() as a constexpr because
// in the return line the function calls a non - 'constexpr' function member
// function size()
// constexpr function cannot contain statements that generate actions at runtime

// constexpr bool isShorter(const string &s1, const string &s2)
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size(); // non - constexpr statement
}
int main(void)
{
    string a = "hello", b = "world!";
    cout << "First string is shorter than second: ";
    cout << (isShorter(a, b) ? "true" : "false") << endl;
    return 0;
}