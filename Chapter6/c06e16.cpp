#include <iostream>
#include <string>

using namespace std;
// this function takes a plain reference to a string as a parameter, so we
// cannot pass a const string or string literal to this function
bool is_empty1(string &s)
{
    return s.empty();
}
// correct aproach is to make 's' a reference to const string, because top-level
// const is ignored when initializing a parameter we can pass both const and
// nonconst object as an argument
bool is_empty2(const string &s)
{
    return s.empty();
}
int main(void)
{
    const string word = "Hello";
    string word2 = "";
    // with first version of this function this generates error
    // cout << is_empty1("hello") << endl;
    // cout << is_empty1(word) << endl;
    cout << is_empty1(word2) << endl;

    // after changing parameter type we can pass string literals and const
    // objects to this function
    cout << is_empty2("hello") << endl;
    cout << is_empty2(word) << endl;

    return 0;
}