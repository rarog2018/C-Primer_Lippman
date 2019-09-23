#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(void)
{
    bitset<32> quiz1 = 0;
    quiz1 = 1ul << 27;
    cout << "quiz1: " << quiz1 << endl;
    cout << "size of unsigned long: " << sizeof(unsigned long) << endl;
    cout << "soze of unsigned int: " << sizeof(unsigned int) << endl;
    // it depends on machine, on my computer both u long
    // and u int have the same size, but on others
    // int can have only 16 bits
    // so 27th bit would not even be represented therefore
    // setting it to 1 would be impossible

    bitset<16> quiz2 = 0;
    quiz2 = 1u << 27;
    cout << "quiz2: " << quiz2 << endl;
}
