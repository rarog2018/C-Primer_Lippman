#include <iostream>
using namespace std;

// when StrBlob object is destroyed the shared_ptr member is destroyed and
// the shared_ptr destructor is used, which might destroy underlying vector
// when StrBlobPtr object is destroyed the weak_ptr member is destroyed and
// the underlying vector remains untouched

int main(void)
{
    return 0;
}