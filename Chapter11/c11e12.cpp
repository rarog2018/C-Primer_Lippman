#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    vector<pair<string, int>> sipvec;
    string word;
    int val;
    while (cin >> word >> val)
    {
        // push_back list initialized pair
        sipvec.push_back({word, val});
    }

    for (const auto &pair : sipvec)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}