#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    // replaces the old_val with new_val in the input range (if it occurs)
    replace(beg, end, old_val, new_val);

    // replaces the element for which the predicate returns true with new_val
    // in the input range
    replace_if(beg, end, pred, new_val);

    // copies elements in the input range to the place denoted by dest iterator
    // and replaces elements with the old_val with new_val
    replace_copy(beg, end, dest, old_val, new_val);

    // copies elements in the input range to the place denoted by dest iterator
    // and replaces elements for which the predicate returns true with new_val
    replace_copy_if(beg, end, dest, pred, new_val);
    return 0;
}