#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    map<string, vector<int>> sivecmap;

    pair<map<string, vector<int>>::iterator, bool> ret =
        sivecmap.insert(pair<string, vector<int>>("hello", {0, 77, 2}));

    // should print 77
    cout << ret.first->second[1] << endl;
    return 0;
}