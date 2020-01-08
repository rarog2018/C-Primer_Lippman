#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
    vector<int> vi{0, 3, 7, 11, 12};
    list<int> li{2, 4, 6, 7};
    // to initialize vector<double> just
    // use the iterators
    vector<double> vd(vi.begin(), vi.end());
    for(const auto &e : vd)
        cout << e << " ";
    cout << endl;

    // same story with list
    vector<double> vd2(li.begin(), li.end());
    for(const auto &e : vd)
        cout << e << " ";
    cout << endl;
}
