#include <iostream>
using namespace std;

int main(void)
{
    int i;

    // the loop will terminate when one of the strm::iostate bits will be set
    // badbit, failbit or eofbit
    // so for example in this case typing a letter or 'CTRL-Z' will do
    while (cin >> i)
    {
        // ...
    }
    return 0;
}