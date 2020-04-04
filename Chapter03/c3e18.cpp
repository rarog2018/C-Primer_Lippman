#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // the code below is illegal, because the vector is empty, hence we cannot
    // assign a value to an nonexistent element
    vector<int> ivec;
    // ivec[0] = 42;

    // to fix it we can use push_back()
    ivec.push_back(42);
    cout << ivec[0] << endl;
    return 0;
}