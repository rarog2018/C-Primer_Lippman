#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    ///////////////////////////         a           ///////////////////////////
    // illegal, ix is an int, not a pointer (or address) to an int
    // IntP p0(ix);

    ///////////////////////////         b           ///////////////////////////
    // illegal, pi is a pointer to i, but it is not dynamically allocated,
    // however p1 will point to that object, the program will exit with an error
    // IntP p1(pi);
    // cout << *p1 << endl;

    ///////////////////////////         c           ///////////////////////////
    // legal, pi2 is a pointer to a dynamically allocated object of type int
    // p2 will point to that object
    IntP p2(pi2);
    cout << *p2 << endl;

    ///////////////////////////         d           ///////////////////////////
    // illegal, &ix is an address of an int object, but it is not a dynamically
    // allocated object,
    // IntP p3(&ix);
    // cout << *p3 << endl;

    ///////////////////////////         e           ///////////////////////////
    // legal, p4 will point to a dynamically allocated int object
    IntP p4(new int(2048));
    cout << *p4 << endl;

    ///////////////////////////         f           ///////////////////////////
    // illegal, p5 will point to the object that p2 points to, which is a disaster
    // multiple unique_ptrs should not point to the same memory at the same time
    // because it will be freed more than once which is an error
    // IntP p5(p2.get());
    // cout << &(*p2) << " " << &(*p5) << endl;

    return 0;
}