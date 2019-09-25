#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v1;
    const vector<int> v2;

    // it1 is vector<int>::iterator
    // its is vector<int>::const_iterator, so they
    // cannot be in one statement
    // auto it1 = v1.begin(), it2 = v2.begin();
    auto it1 = v1.begin();
    auto it2 = v2.begin();

    // it3 is vector<int>::const_iterator
    // it4 is vector<int>::const_iterator
    auto it3 = v1.cbegin(), it4 = v2.cbegin();
}

