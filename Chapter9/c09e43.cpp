#include <iostream>
#include <string>

using namespace std;
void erase_and_insert(string &s, const string &oldVal, const string &newVal);
int main(void)
{
    string s, oldVal, newVal;
    s = "Test your function by using it to replace common abbreviations,"
        "such as tho by though and thru by through. Tho it may be difficult to"
        "do so thru this text sample tho. Yup.";
    oldVal = "tho", newVal = "though";

    cout << s.size() << endl;
    cout << s << endl;
    erase_and_insert(s, oldVal, newVal);
    cout << s.size() << endl;
    cout << s << endl;
    erase_and_insert(s, "thru", "through");
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}

void erase_and_insert(string &s, const string &oldVal, const string &newVal)
{
    // holds the index of a substring that starts like oldVal
    string::size_type pos;
    // loop thru every character in string
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        // if current letter is different than first letter don't bother
        if (*it != *oldVal.begin())
        {
            continue;
        }
        // if current letter equals oldVal's first letter compare next letters
        // with oldVal string
        else
        {
            // remember the start of this substring
            pos = it - s.begin();
            for (auto oVit = oldVal.begin(), fin = oldVal.end(); oVit <= fin && it != s.end(); ++oVit)
            {
                // if the letter in oldVal and letter denoted by it are different
                // break from the loop
                if (*oVit != *it && oVit != fin)
                {
                    break;
                }
                // if letters aren't different and we processed all characters
                // in oldValue
                else if (oVit == fin)
                {
                    // if one letter past oldVal is a letter then break, this
                    // prevents replacing words that are a substring of larger word
                    if (isalpha(*it))
                    {
                        break;
                    }
                    // if one letter past oldVal is a space or dot or other non
                    // alphabetical character
                    else
                    {
                        s.erase(pos, oldVal.size());
                        s.insert(pos, newVal);
                        // validate it by placing it one past newly inserted word
                        it = s.begin() + pos + newVal.size();
                        break;
                    }
                }
                // if letters aren't different and neither of previous conditions
                // occur, increment it
                else
                {
                    ++it;
                }
            }
        }
    }
}