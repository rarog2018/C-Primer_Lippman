#include <iostream>
#include <string>

using namespace std;
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs);
int main(void)
{
    string text{"Assuming T is the name of a type, explain the difference"};
    string::size_type occurs = 0;
    cout << "In string text character 'a' first occurs at index "
         << find_char(text, 'a', occurs) << " and occurs " << occurs
         << " times" << endl;
    return 0;
}
// we use const string &, because we do not want to change the string and at
// the same time we do not want to copy a potentialy large object
// we use char, because we need it only during the time the function is working
// and it is a small object,
// we use string::size_type &, because we want to use and change the original
// variable created outside of this function
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs)
// if we made 's' a plain reference we could possibly mess the original object
// although we can do it if we know that nothing bad will happen
// on the other hand we cannot make 'occurs' a reference to const, because we
// will not be able to change its value (the program won't compile)
{
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0;          // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i; // remember the first occurrence of c
            ++occurs;    // increment the occurrence count
        }
    }
    return ret; // count is returned implicitly in occurs
}