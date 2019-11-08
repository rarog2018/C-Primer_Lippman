#include <iostream>

using namespace std;
/////////////////////       a       /////////////////////
// this declaration is correct
int ff(int a, int b = 0, int c = 0);

/////////////////////       b       /////////////////////
// this declaration is incorrect, because 'wd' and 'bckgrnd' do not heave
// default arguments while being the right-most parameters
// every parameter after one that has a default argument, has to have a default
// argument
// char *init(int ht = 24, int wd, char bckgrnd);

// correct version of b
char *init(int ht = 24, int wd = 10, char bckgrnd = '#');
int main(void)
{
    ff(5);
    return 0;
}
int ff(int a, int b, int c)
{
    cout << a << " " << b << " " << c << endl;
    return a;
}