#include <iostream>
using namespace std;

// The code for declarations look like this
/*
template <typename F>
friend bool operator==(const BlobPtr<F> &, const BlobPtr<F> &);
*/
// because otherwise my compiler was producing a warning statement, that
// operator== is not a template, but at the same time You can't <typename T>
// if T is the same type as the class template's parameter

int main(void)
{
    return 0;
}