#include <iostream>

using namespace std;

int main(void)
{
    // null statement is a statement that consists of a single semicolon
    // personally i sometimes use it in for loops, when i declare variables
    // of more than one type outside the loop
    // happens especially with iterators when we want to use them outside of
    // loop or if/else statement
    ;
    int i = 1;
    double d = 17.31;
    // first statement is a null statement
    for (; i < 5 && (i * d); ++i)
        cout << "Ok" << endl;
    cout << "i: " << i << " d: " << d << endl;
}