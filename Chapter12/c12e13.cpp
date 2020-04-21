#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
    auto sp = make_shared<int>(); // shared_ptr
    auto p = sp.get();            // built-in pointer that points to the same object as sp

    // it will delete the object to which 'p' points, which will make 'sp' a
    // dangling pointer
    delete p;
    return 0;
}