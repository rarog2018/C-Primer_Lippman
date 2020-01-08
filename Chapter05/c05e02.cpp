#include <iostream>

using namespace std;
void printfunction();
int main(void)
// start of a block
{
    // block is a sequence of statements and declarations surounded by a pair
    // of curly brackets; this comment is inside int main(void) block;
    // blocks are useful when we want more than one statement following a loop
    // or an if/else statement or when we want to define function
    if (true)
    // start of a block
    {
        cout << "Typing: ";
        printfunction();
        // end of a block
    }
    else
        return 0;

    // end of a block
}

void printfunction()
// start of a block
{
    cout << "Hello, world" << endl;
    // end of a block
}