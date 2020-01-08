#include <iostream>
#include <cassert>
#include <string>

using namespace std;
int main(void)
{
    string s, sought = "abc";
    // the loop runs until the cin is in a valid state or user types the value
    // of variable sought
    while (cin >> s && s != sought)
    {
    } // empty body

    // when we escape the while loop by typing soughts value the assert will do
    // nothing and the program will terminate without error
    // however if we escape by for example typing CTRL-Z the cin state will
    // change to 'Error' and the assertion will fail
    // It is not a good use of assert because it should be used only to check
    // for conditions that "cannot happen" - cin in error state is definitely
    // not a condition that "cannot happen", quite the opposite based on my
    // experience so far
    assert(cin);
    return 0;
}