#include <bitset>
#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    bitset<32> q (string("01110001"));
    cout << q << endl;
    // i am using bitset for visual purposes, but if 'q' was
    // indeed a char then when promoted to int 'q' would get
    // extra 24 bits with the value of 0, on the left side
    // just like in the cout above
    // then not q '~q' would flip all the bits so all ones
    // would become zeros and all zeros would become ones
    // 00000000 00000000 00000000 01110001
    // 11111111 11111111 11111111 10001110
    // << 6 shifts all the bits 6 positions left adding
    // 6 zeros on the right
    // 11111111 11111111 11100011 10000000
    cout << (~q << 6);
}
