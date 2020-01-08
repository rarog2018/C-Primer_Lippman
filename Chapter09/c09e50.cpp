#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void)
{
    vector<string> s{{"15 3 5 7 8 9 13"}, {"15 3 55 alfa 7 8 9 13"}};
    int sum = 0;
    string::size_type pos;
    for (const auto &str : s)
    {
        // set pos to 0
        pos = 0;
        // find every number in the string
        while ((pos = str.find_first_of("+-.0123456789", pos)) != string::npos)
        {
            // convert first number from this substring
            int temp = stoi(str.substr(pos));
            sum += temp;
            cout << "Processing " << temp << "... the sum is " << sum << endl;
            ++pos;
        }
    }
    cout << sum << endl;
    return 0;
}