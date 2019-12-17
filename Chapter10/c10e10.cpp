#include <iostream>

using namespace std;
int main(void)
{
    // Algorithms don't change the size of the containers because they operate
    // on iterators, not containers itselves, so they do not have access to
    // the container member functions like for example erase()
    return 0;
}