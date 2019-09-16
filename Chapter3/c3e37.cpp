#include <iostream>

using namespace std;

int main()
{
    // declaration of a const char array, it has no NULL character at the end
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    // initialize a pointer to const char to the address of the array
    const char *cp = ca;
    // that's an error prone condition, it will loop until it meets NULL
    // character, but because the given array has no NULL character
    // the results will be interesting (opportunity to know what's
                                        // outside the array :))
    while (*cp) {
    // print the value that pointer points to
    cout << *cp << endl;
    // increment pointer
    ++cp;
    }

    return 0;
}
