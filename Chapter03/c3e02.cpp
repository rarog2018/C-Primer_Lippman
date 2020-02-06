#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string word, sentence;
    cout << "\tType some words: (q to quit)" << endl;
    while (getline(cin, sentence) && sentence != "q")
    {
        cout << sentence << endl;
    }
    cout << "\n\tProgressing to the second while loop: " << endl;
    while (cin >> word && word != "q")
    {
        cout << word << endl;
    }
    return 0;
}