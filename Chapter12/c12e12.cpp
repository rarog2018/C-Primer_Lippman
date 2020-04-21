#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr);

int main(void)
{
    auto p = new int();
    auto sp = make_shared<int>();

    ////////////////////////////        a       ///////////////////////////////
    // legal, just calls the process() using a shared_ptr sp, creates temporary
    // local object, that gets destroyed after process() is finished
    // after: sp still points to the same memory, reference count is 1
    process(sp);
    cout << "value: " << *sp << ", reference count: " << sp.use_count() << endl;

    ////////////////////////////        b       ///////////////////////////////
    // illegal, it is not possible to implicitly convert a built-in pointer to
    // a shared_ptr
    // process(new int());

    ////////////////////////////        c       ///////////////////////////////
    // illegal, same story as in b), 'p' is a built-in pointer
    // process(p);

    ////////////////////////////        d       ///////////////////////////////
    // legal, explicitly converts built-in pointer to a shared_ptr
    // the local shared_ptr 'ptr' now points to the same object in memory as 'p'
    // because 'ptr' gets destroyed after process() is finished, the object will
    // be destroyed, which will make 'p' a dangling pointer
    cout << "value of p before process: " << *p << endl;
    process(shared_ptr<int>(p));
    cout << "value of p after process: " << *p << endl;

    return 0;
}

// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
    // use ptr
} // ptr goes out of scope and is destroyed and count is decremented