#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;
    auto it = scores.begin();
    while (cin >> grade)            // read the grades
    {
        if (grade <= 100)           // handle only valid grades
        {
            ++(*(it + (grade/10))); // increment the counter for the current cluster
        }
    }
    for (auto it = scores.cbegin(); it != scores.cend(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
