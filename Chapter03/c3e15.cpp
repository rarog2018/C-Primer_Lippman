#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    string a;
    vector<string> svec;
    while (cin >> a)
    {
        svec.push_back(a);
    }

    for (auto &e : svec)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}