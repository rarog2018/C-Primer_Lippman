#include <iostream>

using namespace std;

int main(void)
{
    int i = 2, j = 2;
    double d = 2.9989245;
    // when we cast the value of 'd' will be
    // truncated, so the expression will be
    // (2 * 2) instead of (2.0 * 2.7989245)
    i *= static_cast<int>(d);
    cout << "i = " << i << " value of the expression: "
        << (2 * static_cast<int>(d)) << endl;

    // here we can see that result is indeed different
    i = 2;
    i *= d;
    cout << "i = " << i << " value of the expression: "
        << (j * d) << endl;
}
