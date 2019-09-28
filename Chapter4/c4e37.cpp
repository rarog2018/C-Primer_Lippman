#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int i = 1;
    double d = 1.25;
    const string hellos{"World"};
    const string *ps = &hellos;
    char cvar = 'z';
    char *pc = &cvar;
    void *pv = NULL;

    // finally
    pv = static_cast<void *>(const_cast<string *>(ps));
    cout << pv << endl;
    // pc points to cvar which holds character 'z'
    // this instruction converts 'z' to integer (122)
    i = static_cast<int>(*pc);
    cout << i << endl;

    pv = static_cast<void *>(&d);
    cout << pv << endl;

    pc = static_cast<char *>(pv);
    cout << *pc << endl;
    return 0;
}
