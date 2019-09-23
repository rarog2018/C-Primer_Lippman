#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{
    bitset<32> ul1 = 3, ul2 = 7;
    // result should be 3 bytes of zeros and 00000011
    cout << "ul1: " << ul1 << endl;
    // result should be 3 bytes of zeros and 00000111
    cout << "ul2: " << ul2 << endl;

    // bitwise and & operator will evaluate each bit to true
    // if corresponding bit in both ul1 and ul2 is set
    // to 1 otherwise it will be false
    // result should be 3 bytes of zeros and 00000011 = 3
    cout << "ul1 & ul2: " << (ul1 & ul2) << endl;

    // bitwise or | operator will evaluate each bit to true
    // if corresponding bit in ul1 or ul2 is set to 1
    // if both ul1 and ul2 bits are zeros then the result
    // bit is also zero
    // result should be 3 bytes of zeros and 00000111 = 7
    cout << "ul1 | ul2: " << (ul1 | ul2) << endl;

    unsigned long ul3 = 3, ul4 = 7;
    // logical and && operator will evaluate this expression
    // to true, because both values are nonzero
    cout << "ul1 && ul2: " << (ul3 && ul4) << endl;

    // logical or || operator will evaluate this expression
    // to true, because at least one of the values is nonzero
    cout << "ul1 || ul2: " << (ul3 || ul4) << endl;
}
