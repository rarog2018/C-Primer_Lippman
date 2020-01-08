#include <iostream>

using namespace std;

int main(void)
{
    // -30 * 3 = -90, then 21 / 5 = 4, then -90 + 4 = -86
    cout << "-30 * 3 + 21 / 5 is equal: " << -30 * 3 + 21 / 5 << endl;
    // 3 * 21 = 63, then 63 / 5 = 12, then -30 + 12 = -18
    cout << "-30 + 3 * 21 / 5 is equal: " << -30 + 3 * 21 / 5 << endl;
    // 30 / 3 = 10, then 10 * 21 = 210, then 210 % 5 = 0
    cout << "30 / 3 * 21 % 5 is equal: " << 30 / 3 * 21 % 5 << endl;
    // - 30 / 3 = -10,then -10 * 21 = -210, then -210 % 4 = -2
    cout << "-30 / 3 * 21 % 4 is equal: " << -30 / 3 * 21 % 4 << endl;
}
