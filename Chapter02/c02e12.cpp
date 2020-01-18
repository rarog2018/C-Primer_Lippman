#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // invalid: 'double' is a C++ reserved keyword, it cannot be used as a
    // variable name
    // int double = 3.14;

    /////////////////////           b           //////////////////////////////
    // valid
    int _;
    cout << &_ << endl; // proof

    /////////////////////           c           //////////////////////////////
    //  invalid: 'catch' is a C++ reserved keyword, it cannot be used as a
    // variable name, second thin is that there has to be an initializer before
    // using '-' operator, so even if the name was legal the statement is not
    // int catch - 22;

    /////////////////////           d           //////////////////////////////
    // invalid: names must begin with a letter or underscore
    // int 1_or_2 = 1;

    /////////////////////           e           //////////////////////////////
    // valid
    double Double = 3.14;
    cout << Double << " " << &Double << endl;

    return 0;
}