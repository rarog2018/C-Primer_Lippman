#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string sentence("Evil is evil, Stregobor."), temp;
    temp = sentence;
    cout << temp << endl;

    //////////////      range for       ///////////////////
    // change all characters to 'X'
    for (auto &c : temp)
    {
        c = 'X';
    }

    // print the result
    cout << temp << endl;

    //////////////      regular for       ///////////////////
    temp = sentence;
    cout << temp << endl;

    for (string::size_type index = 0; index != temp.size(); ++index)
    {
        temp[index] = 'X';
    }
    cout << temp << endl;

    //////////////      while       ///////////////////
    temp = sentence;
    cout << temp << endl;

    string::size_type index = 0, max = temp.size();
    while (index != max)
    {
        temp[index] = 'X';
        ++index;
    }
    cout << temp << endl;

    // the simpliest to use is the range for, because it has predefined
    // condition from where to start and where to end
    return 0;
}