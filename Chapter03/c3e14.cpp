#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int a;
    vector<int> ivec;
    while (cin >> a)
    {
        ivec.push_back(a);
    }

    for (auto &e : ivec)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}