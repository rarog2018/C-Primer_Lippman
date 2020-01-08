#include <iostream>
#include <string>

using namespace std;
void replace_word(string &s, const string &oldVal, const string &newVal);
int main(void)
{
    string s, oldVal, newVal;
    s = "Test your function by using it to replace common abbreviations,"
        "such as tho by though and thru by through. Tho it may be difficult to"
        "do so thru this text sample tho. Yup.";
    oldVal = "tho", newVal = "though";

    cout << s.size() << endl;
    cout << s << endl;
    replace_word(s, oldVal, newVal);
    cout << s.size() << endl;
    cout << s << endl;
    replace_word(s, "thru", "through");
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}

void replace_word(string &s, const string &oldVal, const string &newVal)
{
    // holds the index of a substring that starts like oldVal
    string::size_type pos;
    // loop thru every character in string
    for (string::size_type i = 0; i != s.size(); ++i)
    {
        // if current letter is different than first letter don't bother
        if (s[i] != oldVal[0])
        {
            continue;
        }
        // if current letter equals oldVal's first letter compare next letters
        // with oldVal string
        else
        {
            // remember the start of this substring
            pos = i;
            for (string::size_type j = 0, fin = oldVal.size(); j <= fin && j != s.size(); ++j)
            {
                // if the letter in oldVal and letter denoted by i are different
                // break from the loop
                if (oldVal[j] != s[i] && j != fin)
                {
                    break;
                }
                // if letters aren't different and we processed all characters
                // in oldValue
                else if (j == fin)
                {
                    // if one letter past oldVal is a letter then break, this
                    // prevents replacing words that are a substring of larger word
                    if (isalpha(s[i]))
                    {
                        break;
                    }
                    // if one letter past oldVal is a space or dot or other non
                    // alphabetical character
                    else
                    {
                        s.replace(pos, oldVal.size(), newVal);
                        // validate i by placing it one past newly inserted word
                        i = pos + newVal.size();
                        break;
                    }
                }
                // if letters aren't different and neither of previous conditions
                // occur, increment it
                else
                {
                    ++i;
                }
            }
        }
    }
}