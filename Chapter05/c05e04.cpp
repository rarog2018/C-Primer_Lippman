#include <iostream>
#include <string>

using namespace std;
bool find(string a);
int main(void)
{
    string s{"Hello"};
    string word = "z";
    // iter is not initialized, not bound to a proper string,even if it was
    // correct to declare iter inside while loop condition, this particular
    // declaration would result in infinite loop
    //while (string::iterator iter != s.end()){/* */}

    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        cout << *iter << " ";
        ++iter;
    }

    // variable status is used in if statement outside the while loop, but
    // it is visible only inside the while loop
    /* while (bool status = find(word)) {  . . .  } if (!status)
    {  . . . } */

    // just declare the variable before the while loop
    bool status;
    while (status = find(word))
    {
        cout << "Found it" << endl;
        break;
    }

    if (!status)
        cout << "Not found, what now?" << endl;
}

bool find(string a)
{
    return false;
}