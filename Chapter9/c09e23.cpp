#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> c{15};
    if (!c.empty())
    {
        // val and val2 are copies of the value of the first element in c
        // the first el ist 15 so their value is 15
        auto val = *c.begin(), val2 = c.front();
        // val3 and val4 are copies of the of the last element in c
        // c has only one element so their value is also 15
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();

        cout << "val: " << val << "\nval2: " << val2 << "\nval3: "
             << val3 << "\nval4: " << val4 << endl;
    }
    return 0;
}