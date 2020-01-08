#include <iostream>

using namespace std;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    int *p1 = &arr[1];
    int *p2 = &arr[3];
    int *p3 = &arr[1];
    cout << "p1: " << *p1 << " p2: " << *p2 << endl;
    // the code below is equal to p1 = p1 + p2 - p1
    // which mathematically is just p2
    // the code will be illegal if p2 points to the
    // element outside of the arrays range
    p1 += p2 - p1;
    // p1 = p2; is exactly the same
    p1 = &arr[1];
    // proof
    if ((p1 == p3) && ((p1 += p2 - p1) == (p3 = p2)))
        cout << "\nTrue" << endl;
    return 0;
}
