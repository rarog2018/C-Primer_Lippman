#include <iostream>

using namespace std;
void manip(int a, int b);
double dobj = 1.17;
int main(void)
{
    ///////////////////////         a           ///////////////////////
    // Rank 3 -> Match through a promotion. Both chars are promoted to int.
    manip('a', 'z');

    ///////////////////////         b           ///////////////////////
    // Rank 4 -> Match through an arithmetic conversion. Both doubles are
    // converted to an integer.
    manip(55.4, dobj);
    return 0;
}
void manip(int a, int b)
{
    cout << a << " " << b << endl;
}