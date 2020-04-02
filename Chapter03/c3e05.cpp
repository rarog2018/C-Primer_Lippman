#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string concatenatedString, word;
    // read the user input and store it all in one variable
    while (cin >> word)
    {
        concatenatedString += word + " ";
    }

    // print the result
    cout << concatenatedString << endl;
    return 0;
}