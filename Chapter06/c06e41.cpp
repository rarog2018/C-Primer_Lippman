#include <iostream>

using namespace std;
char tab = 'z';
char *p = &tab;
char *init(int ht, int wd = 80, char bckgrnd = ' ');
int main(void)
{
    //////////////////////      a       ///////////////////////
    // this call is illegal, because too few arguments are provided
    // 'ht' does not have a default argument, so we have to pass it ourself
    // init();

    //////////////////////      b       ///////////////////////
    // this call is legal, 'ht' = 24, 'wd' = 10, 'bckgrnd' = ' '
    init(24, 10);

    //////////////////////      c       ///////////////////////
    // this call is legal but most likely the intention was different
    // 'ht' = 14, 'wd' = 42 (because '*' converted to int is 42), 'bckgrnd' = ' '
    init(14, '*');
    return 0;
}
char *init(int ht, int wd, char bckgrnd)
{
    for (int i = 0; i != ht; ++i)
    {
        for (int j = 0; j != wd; ++j)
        {
            cout << bckgrnd;
        }
        cout << endl;
    }
    return p;
}