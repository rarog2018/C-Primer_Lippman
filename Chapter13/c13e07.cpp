#include <iostream>
using namespace std;

// when we assign one StrBlob to another, the shared_ptr is copied, so the new
// StrBlob has a shared_ptr that points to the same dynamically allocated
// vector as the original StrBlob object

// when we assign one StrBlobPtr to another the same thing happens

int main(void)
{
    return 0;
}