#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    // if e % 2 is positive double the element value
    // if its not leave its current value
    for(auto &e : vec)
        e = (e % 2) ? e * 2 : e;

    for(const auto e : vec)
        cout << e << " ";
}
