#include <iostream>
#include <memory>
using namespace std;

/*unique_ptr<int> clone(int p)
{
    // ok: explicitly create a unique_ptr<int> from int*
    return unique_ptr<int>(new int(p));
}*/
unique_ptr<int> clone(int p)
{
    unique_ptr<int> ret(new int(p));
    // lets print the addres to which ret points
    cout << "Address of local unique_ptr variable: " << &ret
         << "    Address of the value: " << &(*ret) << endl;
    return ret;
}

// the code above is valid, because the compiler know that the localy created
// unique_ptr will be destroyed when the function finishes, so it will use
// move() to "copy" the pointer (the function returns rvalue)

int main(void)
{
    int a = 5;
    // int *pa = &a;
    unique_ptr<int> aup = clone(a);
    cout << "Address of main unique_ptr variable: " << &aup
         << "    Address of the value: " << &(*aup) << endl;
    // as we can see the addresses match, because move() was used instead of
    // copying
    return 0;
}