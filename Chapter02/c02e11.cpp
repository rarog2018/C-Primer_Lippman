#include <iostream>
using namespace std;
/////////////////////           a           //////////////////////////////
// it is definition, because initialization overrides extern
// compiler will warn us about this override
// warning: 'ix' initialized and declared 'extern'
extern int ix = 1024;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // trying to override extern inside a function is an error
    // error: 'ix' has both 'extern' and initializer
    // extern int ix = 1024;

    /////////////////////           b           //////////////////////////////
    // it is a definition, iy gets value initialized with some garbage value
    int iy;

    /////////////////////           c           //////////////////////////////
    // it is a declaration, iz is uninitialized
    extern int iz;

    cout << "ix value: " << ix << " address: " << &ix << endl;
    cout << "iy value: " << iy << " address: " << &iy << endl;
    // this line produces an error: undefined reference to 'iz', because the
    // variable is only declared it does not have nor a value nor an allocated
    // storage in memory
    // cout << "iz value: " << iz << " address: " << &iz << endl;
    return 0;
}