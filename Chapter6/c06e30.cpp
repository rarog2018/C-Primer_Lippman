#include <iostream>
#include <string>

using namespace std;
bool str_subrange(const string &str1, const string &str2);
int main(void)
{
    string a = "abc", b = "abc", c = "abcde", d = "xyz", e = "abef";
    cout << (str_subrange(a, b) ? "equal" : "unequal") << endl;

    // so it seems that on my computer function returns true by default when
    // sizes are unequal and we get outside of a for loop, even if there is no
    // return statement after for loop
    cout << (str_subrange(a, c) ? "equal" : "unequal") << endl;
    cout << (str_subrange(a, d) ? "equal" : "unequal") << endl;
    cout << (str_subrange(a, e) ? "equal" : "unequal") << endl;
    return 0;
}

// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{

    if (str1.size() == str2.size())
    {
        cout << "strings have equal size and their contents are ";
        return str1 == str2;
    }

    auto size = (str1.size() < str2.size())
                    ? str1.size()
                    : str2.size();

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
        {
            cout << "(in for) strings have unequal size and their contents are ";
            return false;
            // return; // error #1: my compiler detects this and program does
            // not compile
        }
    }
    cout << "(out for) strings have unequal size and their contents are ";
    // when error #1 is fixed, my compiler compiles the code but there is a
    // warning: control reaches end of non-void function [-Wreturn-type]
}