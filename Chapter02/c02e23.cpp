#include <iostream>
using namespace std;

int main(void)
{
    // it is not possible (at least with plain basic pointers) wheter it points
    // to a valid object or not
    // the memory contains 0s and 1s and it is impossible without knowing the
    // type of the object in the memory what it really represents
    // 0000101010101 even if we have an address to the first zero we do not know
    // how many following numbers are the object, is it 4 bytes? or 8 bytes?
    // how to interpret it? we just don't know what the 0s and 1s represent,
    // and where one object starts and ends,
    return 0;
}