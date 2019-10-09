#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    // vector's size is the number of elements it already hold, while capacity
    // is how many elements it can hold before more space must be allocated
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // here we see that capacity and size are the same
    cout << "Vector size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;
    ivec.push_back(10); // vector gets reallocated
    // after adding one element the capacity is 20 and the size is 11, so we can
    // place 9 more elements before we will need to reallocate the vector
    cout << "Vector size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;
    return 0;
}