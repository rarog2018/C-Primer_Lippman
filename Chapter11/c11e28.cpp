#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    map<string, vector<int>> sivecmap{{"hello", {5, 14, 22}}};
    map<string, vector<int>>::iterator it = sivecmap.find("hello");

    cout << it->first << endl;
    cout << it->second[2] << endl;
    return 0;
}