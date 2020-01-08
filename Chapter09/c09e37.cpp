#include <iostream>
#include <list>
#include <array>

using namespace std;
int main(void)
{
    // array does not have capacity member because size is a part of its type,
    // it's fixed and it is its capacity at the same time, so we can say that
    // array's size = array's capacity
    array<int, 20> arri{0, 1, 2, 3, 4, 5};
    // array always has as many elements as its size, even if we assign a value
    // only to couple of them
    for (const auto &e : arri)
    {
        cout << e << " ";
    }
    cout << endl;

    // elements in list are not contiguous, so there is no need to reallocate
    // them, so no need to prepare memory for them, because they can use any
    // available memory.
    return 0;
}