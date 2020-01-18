#include <iostream>
using namespace std;

int main(void)
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    cout << "i = " << i << ", d = " << d << endl;
    /////////////////////           a           //////////////////////////////
    // valid, it changes the value of the object to which 'r2' is bind, which
    // in this case is 'd'
    r2 = 3.14159;
    cout << "after r2 = 3.14159: d = " << d << endl;

    /////////////////////           b           //////////////////////////////
    // valid, changes the value of 'd' to the value of 'r1', which is 0
    r2 = r1;
    cout << "after r2 = r1: d = " << d << endl;

    /////////////////////           c           //////////////////////////////
    // valid, assigns the value of r2 to i
    i = r2;
    cout << "after i = r2: i = " << i << endl;

    /////////////////////           d           //////////////////////////////
    // valid, changes the value of 'i' to the value of 'd'
    r1 = d;
    cout << "after r1 = d: i = " << i << endl;

    return 0;
}