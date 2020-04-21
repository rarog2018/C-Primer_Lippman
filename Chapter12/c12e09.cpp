#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
    // creates two built-in pointers, each points to a dynamically allocated,
    // value initialized object of type int
    int *q = new int(42), *r = new int(100);
    // now r points to the same address that 'q' points to,
    // the memory that 'r' pointed to before was not freed and we will have no
    // access to it anymore -> memory leak
    r = q;

    // creates two shared_ptrs, each points to a dynamically allocated, value
    // initialized object of type int
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    // now 'r2' points to the same address that 'q2' points to,
    // the memory that 'r2' pointed to before was automaticaly freed by
    // shared_ptr destructor, because the shared_ptr count dropped to zero
    // after that assignment happened, because there was no smart pointer pointing
    // to that memory
    r2 = q2;

    cout << *q << " " << *r << " " << *q2 << " " << *r2 << endl;
    return 0;
}