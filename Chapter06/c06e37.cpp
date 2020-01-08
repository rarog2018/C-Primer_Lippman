#include <iostream>
#include <string>

using namespace std;
// type alias
typedef string arrS[10];
arrS &func1();

// trailing return
auto func2() -> string (&)[10];

// decltype
string arr[10];
decltype(arr) &func3();

// iprefer type alias, because C was my first language and it does not look
// as cryptic as the other 2 options
int main(void)
{
    return 0;
}