#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(void)
{
    vector<double> v{1.25, 0.75, 13.55};
    // 0 is an int value so the type that accumulate will return is int, so
    // the result will not be correct
    // 1.25 + 0.75 = 2; 13.55 + 2 = 15.55, yet the result is 14, because
    // 1 + 0 + 13 = 14
    cout << "Sum of v is " << accumulate(v.cbegin(), v.cend(), 0) << endl;

    // to correct this we pass 0.0 as third argument which has type double
    cout << "Sum of v is " << accumulate(v.cbegin(), v.cend(), 0.0) << endl;
    return 0;
}