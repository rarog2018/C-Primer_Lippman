#include <iostream>

using namespace std;
int get_value();
int main(void)
{
    int ival1 = 3, ival2 = 3, minval = 1;
    bool occurs = 0;

    if (ival1 != ival2)
        ival1 = ival2; // there was no semicolon
    else
        ival1 = ival2 = 0; // vsc corrects the indentation automatically
    cout << "ival1: " << ival1 << " ival2: " << ival2 << endl;

    if (ival1 < minval) // there was no brackets, so probably occurs variable
    {                   // was ment to have value of 1 only if the condition
        minval = ival1; // was true, but without brackets 1 would be assigned
        occurs = 1;     // every time program was run
    }
    cout << "ival1: " << ival1 << " minval: " << minval
         << " occurs: " << occurs << endl;

    //if (int ival = get_value()) // ival does not exist outside this if scope
    int ival; // now ival can be used in second if statement
    if (ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";

    //if (ival = 0) // assigns 0 to ival, but it means to check if ival is 0
    if (ival == 0)
        ival = get_value();
    cout << "ival: " << ival << endl;
}

int get_value()
{
    return 7;
}