#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string sentence("Evil is evil, Stregobor.");
    cout << sentence << endl;

    // change all characters to 'X'
    for (auto &c : sentence)
    {
        c = 'X';
    }

    // print the result
    cout << sentence << endl;
    return 0;
}