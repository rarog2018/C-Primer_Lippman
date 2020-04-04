#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(void)
{
    vector<string> svec;
    string word;

    // read the user input and store it in a vector
    while (cin >> word)
    {
        svec.push_back(word);
    }

    // process the vector and change each word to uppercase
    for (auto &s : svec) // each string in the vector
    {
        for (auto &c : s) // each character in a string
        {
            c = toupper(c); // change to uppercase
        }
    }

    // print the transformed elements, eight words to a line
    for (vector<string>::size_type i = 0; i != svec.size(); ++i)
    {
        if (!(i % 8)) // add new line if i mod 8 is zero
        {
            cout << endl;
        }
        cout << svec[i] << " ";
    }

    cout << endl;
    return 0;
}