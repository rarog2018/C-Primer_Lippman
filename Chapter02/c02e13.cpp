#include <iostream>
using namespace std;

int i = 42;
int main()
{
    int i = 100;
    // j = 100, because it uses 'i' from the local scope
    int j = i;
    cout << "j = " << j << "\nlocal i = " << i << "\nglobal i = " << ::i << endl;
}