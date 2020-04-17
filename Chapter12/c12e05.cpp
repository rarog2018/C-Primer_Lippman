#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
/*
// construct vector of strings from the initializer_list
StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
*/

// Cons: we may not notice when the implicit conversion that we did not
// intended to happen happens
// Pros: we could do this:
// StrBlob b2 = {"a", "an", "the"};
// we can pass such list as above to the functions that have a StrBlob parameter

int main(void)
{
    return 0;
}