#include <iostream>

using namespace std;
int main(void)
{
    size_t sz = 10;
    ///////////////        a       ///////////////
    // the loop is ok, but we use ix variable outside of it in if statement
    // so we have to initialize ix before the for loop
    //for (int ix = 0; ix != sz; ++ix)
    int ix;
    for (ix = 0; ix != sz; ++ix)
    {
        /* . . . */
    }
    if (ix != sz)
        cout << "ix != sz" << endl;

    ///////////////        b       ///////////////
    // the loop is invalid because it omits the initializer incorrectly
    // there has to be a semicolon which represents a null init-statement
    // also ix needs to have a valid value
    // the loop means execute the code in the block untill ix is not equal sz
    // increment ix after each block execution
    // int ix;
    // for (ix != sz; ++ix)
    /* int */ ix = 0;
    for (; ix != sz; ++ix)
    {
        /* . . . */
    }

    ///////////////        c       ///////////////
    // the loops seems to be fine, but in the expression we increment sz each
    // new iteration and we compare ix to sz in a condition, so unless there
    // is a proper solution for this in the loop code block, the loop will run
    // infinitely
    for (int ix = 0; ix != sz; ++ix, ++sz)
    {
        /* . . . */
        ++ix;
        cout << ix << " " << sz << endl;
    }
}