#include <iostream>

using namespace std;

int main(void)
{
    // binary '*', '/' and '%' operators have the same priority
    // '+' has less priority than 3 above, so it will be computed last
    cout << (((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2) << endl;
    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
}
