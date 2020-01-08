#include <iostream>

using namespace std;
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
// returns a reference to an array of five int elements
typedef int arrS[5];
arrS &arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
int main(void)
{
    cout << *arrPtr(1) << endl;
    cout << *arrPtr(2) << endl;
    return 0;
}