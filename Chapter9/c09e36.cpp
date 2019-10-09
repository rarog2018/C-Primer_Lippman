#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    // no it can't be less than the size
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Initial Vector size: " << ivec.size() << " capacity: "
         << ivec.capacity() << endl;

    ivec.push_back(10); // vector gets reallocated
    cout << "After push_back Vector size: " << ivec.size() << " capacity: "
         << ivec.capacity() << endl;

    ivec.shrink_to_fit();
    cout << "After shrink_to_fit Vector size: " << ivec.size() << " capacity: "
         << ivec.capacity() << endl;

    ivec.resize(5);
    cout << "After resize(5) Vector size: " << ivec.size() << " capacity: "
         << ivec.capacity() << endl;
    // as we can see shrink_to_fit() can only change capacity to the current size
    // of the vector, and resize() does not change capacity at all, so there is
    // no way to change capacity to be less than size
    return 0;
}