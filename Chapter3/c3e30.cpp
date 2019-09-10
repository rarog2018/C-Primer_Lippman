#include <iostream>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    int cnt = 0;
    // we assign 1 to ix instead of 0 and then assign ix to ia[ix], which means
    // that we will not assign anything to ia[0] which will leave it with garbage
    // value
    // not to mention that we actually run the loop 10 times, and trying to assign
    // to nonexistent ia[10] element, going outside of this arrays range
    for (size_t ix = 1; ix <= array_size; ++ix, cnt++)
        ia[ix] = ix;
    for (auto el : ia)
        cout << el << " ";
    cout << "\n" << cnt << "\n" << ia[10];
    return 0;
}
