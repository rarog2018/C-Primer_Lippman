#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    bool occured = false;
    string word, last_word = "";
    cout << "Type some words: " << endl;
    while (cin >> word)
    {
        if (word == last_word)
        {
            occured = true;
            break;
        }
        last_word = word;
    }
    if (occured)
    {
        cout << word << " occured twice in succession." << endl;
    }
    else
        cout << "No word has been repeated." << endl;
    return 0;
}