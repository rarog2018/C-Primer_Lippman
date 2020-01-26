#include <iostream>
using namespace std;

int main(void)
{
    // Auto ignores top-level const while decltype does not
    const int i = 5;
    auto j = i;        // j is a plain int
    decltype(i) k = 7; // k is a const int

    // Auto ignores the reference, decltype does not
    int &l = j;
    auto m = l;        // m is a plain int, reference is being ignored
    decltype(l) n = l; // n is a reference to int bount to 'l'

    // Example of the same result from auto and decltype:
    // both 'b' and 'c' are plain ints
    int a = 5;
    auto b = 8;
    decltype(a) c = 9;

    return 0;
}