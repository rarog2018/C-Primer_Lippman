#include <iostream>
using namespace std;

// Postfix increment works with the memory to which the pointer points, before
// it is incremented. In this case first_free points to the raw, unconstructed
// memory that is adjacent to the last constructed item.
// Passing first_free++ to construct, constructs an item in the memory adja-
// cent to last constructed item, and then increments the pointer to point to
// memory adjacent to the newly created item
// If we used ++first_free, we would immediately point to another chunk of
// unconstructed memory, that is adjacent to the unconstructed memory to which
// first_free pointed before increment

// first_free++
// |item1| |item2| |unconstructed| |unconstructed| |unconstructed|
//                 ^ here points first_free, and here the item'll be constructed
// |item1| |item2| |item3| |unconstructed| |unconstructed|
//                          ^ now first_free points here

// ++first_free
// |item1| |item2| |unconstructed| |unconstructed| |unconstructed|
//                                  ^ first_free would jump here
// |item1| |item2| |unconstructed| |item3| |unconstructed|
//                                  ^ first_free still points here

int main(void)
{
    return 0;
}