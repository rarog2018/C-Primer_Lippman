#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(void)
{
    int n = 5;
    // string *const p = new string[n]; // construct n empty strings
    // we don't have to construct all the allocated memory, we can use allocator
    allocator<string> alloc; // allocator object
    // allocate raw unconstructed memory, p point to the beginning
    auto p = alloc.allocate(n);
    auto q = p; // will be our iterator
    string s;
    // string *q = p; // q points to the first string

    while (cin >> s && q != p + n) // standard pointer arithmetic
    {
        // *q++ = s; // assign a new value to *q
        alloc.construct(q++, s); // each time advance q
    }
    const size_t size = q - p; // remember how many strings we read
    // use the array
    for (auto iter = p; iter != p + size; ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // delete[] p; // p points to an array; must remember to use delete[]
    while (q != p)
    {
        // destroy elements from the last constructed to first
        alloc.destroy(--q);
    }
    alloc.deallocate(q, n); // deallocate the memory
    return 0;
}