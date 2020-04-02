#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string sentence;
    // get the string with punctation
    getline(cin, sentence);
    cout << endl;

    // remove the punctation
    for (auto &c : sentence)
    {
        if (ispunct(c))
        {
            continue;
        }
        else
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}