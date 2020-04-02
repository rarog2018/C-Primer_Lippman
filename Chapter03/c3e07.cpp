#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string sentence("Evil is evil, Stregobor.");
    cout << sentence << endl;

    // nothing will happen because the type of the control variable is char anyway
    // change all characters to 'X'
    for (char &c : sentence)
    {
        c = 'X';
    }

    // print the result, which is the same as in previous exercise
    cout << sentence << endl;
    return 0;
}