#include <iostream>

using namespace std;
int get_response();
int main(void)
{
    ////////////////        a       ////////////////
    // except for the lack of curly brackets the loop is ok, it sums 2 numbers
    /*do
        int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
    while (cin);*/

    do
    {
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    } while (cin);

    ////////////////        b       ////////////////
    // initialization in condition of do while loop is not allowed
    /*do
    {
        // . . .
    } while (int ival = get_response());*/
    int ival; // declaration has to be before loop
    do
    {
        // . . .
        cout << "Inside a 'do... while' loop" << endl;
    } while (ival = get_response());

    ////////////////        c       ////////////////
    // the loop is legal, although declaring new condition variable like that
    // might not be the best design
    do
    {
        int ival = get_response();
        cout << ival << endl;
    } while (ival);

    return 0;
}

int get_response()
{
    return 0;
}
