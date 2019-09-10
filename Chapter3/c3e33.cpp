#include <iostream>

using namespace std;

int main()
{
    // count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
    unsigned scores[11];    // 11 buckets, without initialization there will be garbage values
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100)
        ++scores[grade/10]; // increment the counter for the current cluster
    }
    for (unsigned i = 0; i != 11; i++)
    {
        cout << scores[i] << " ";
    }
    return 0;
}
