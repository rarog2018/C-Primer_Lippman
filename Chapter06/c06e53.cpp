#include <iostream>

using namespace std;
///////////////////////         a           ///////////////////////
// Thanks to the second declaration we now have an option to pass a refence
// to const int, which would make first declaration cause an compilation error
// error: binding reference of type 'int&' to 'const int' discards qualifiers
// So it is a legal set of declarations
int calc(int &, int &);
int calc(const int &, const int &);

///////////////////////         b           ///////////////////////
// It has the same effect as above - now we can pass also const char *
// It is a legal set of declarations
int calc(char *, char *);
int calc(const char *, const char *);

///////////////////////         c           ///////////////////////
// This is illegal because top-level const is omitted in parameter list, so
// error: redefinition of 'int calc(char*, char*)'
// and the program obviously will not compile
int calc(char *, char *);
int calc(char *const, char *const);
int main(void)
{
    int a = 2, b = 3;
    const int c = 4, d = 5;
    char e = 'e', f = 'f';
    char *const g = &e, *h = &f;
    calc(a, b);
    calc(c, d);
    calc(g, h);
    return 0;
}

int calc(int &, int &)
{
    cout << "calc(int &, int &)" << endl;
    return 0;
}
int calc(const int &, const int &)
{
    cout << "calc(const int &, const int &)" << endl;
    return 0;
}

int calc(char *, char *)
{
    cout << "calc(char *, char *)" << endl;
    return 0;
}
int calc(const char *, const char *)
{
    cout << "calc(const char *, const char *)" << endl;
    return 0;
}

int calc(char *const, char *const)
{
    cout << "calc(char *const, char *const)" << endl;
    return 0;
}