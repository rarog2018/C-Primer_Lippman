#include <iostream>
using namespace std;

// if the return type of move(), set() and display() was Screen instead of
// Screen&, then the 'myScreen' object would be remain unchanged while the
// functions would perform their code on the copy of it
// the line: myScreen.move(4, 0).set('#').display(cout); would be performed on
// the copy, and in next line we would see that the object itself is unchanged

int main(void)
{
    return 0;
}