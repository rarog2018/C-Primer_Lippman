#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    const string s = "Keep out!";
    for (auto &c : s)
    {
        /* ... */
    }
    // it is legal, the type of c is: const char &
    return 0;
}