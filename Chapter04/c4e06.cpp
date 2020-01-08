#include <iostream>

using namespace std;

int main(void)
{
    int val;
    cout << "Type int value: ";
    cin >> val;
    // if the remainder of dividing val by 2 is not 0
    // then val is odd (in this case the remainder can
                        // only be 0 or 1)
    if (val % 2)
        cout << val << " is odd." << endl;
    else
        cout << val << " is even." << endl;
}
