#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string first, second, answer;
    do
    {
        cout << "Give me contents for two strings: " << endl;
        cout << "First: ";
        getline(cin, first);
        cout << "Second: ";
        getline(cin, second);
        cout << "First string is " << ((first == second) ? "equal to second." : (first > second) ? "more than second." : "less than second.")
             << "\nWant to compare more? yes / no: ";
        getline(cin, answer);
        cout << endl;
    } while (!answer.empty() && answer[0] != 'n');

    return 0;
}