#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
/* void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
} */
// size_type is an unsigned type, so 'i' cannot be lesser than 0
// when 'i' equals 0 then the exception will be always thrown

int main(void)
{
    return 0;
}