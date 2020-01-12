#include <iostream>
using namespace std;
int main(void)
{
    // both values are int and both are integer literals, so their values are
    // '9' and '7' respectively
    int month = 9, day = 7;
    cout << "month: " << month << " day: " << day << endl;
    //  both values are int and both are octal integer literals, so their values
    // are error, because the values should be from range 0-7, so 9 is too big,
    // and '8' respectively
    int month2 = 09, day2 = 07; // error: invalid digit "9" in octal constant
    // int month2 = 011, day2 = 07;
    cout << "month: " << month2 << " day: " << day2 << endl;
    return 0;
}