#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr);

int main(void)
{
    // ok, p is a shared_ptr that points to a dynamically allocated, value ini-
    // tialized object of type int, created with 'new' keyword
    shared_ptr<int> p(new int(42));
    // because the parameter is not a reference, when the function is called it
    // creates a temporary shared_ptr that points to that object, which incre-
    // ments the shared_ptr count
    // that temporary object is destroyed after it gets out of scope, but it
    // does not impact our 'p' shared_ptr
    // The function call is correct.
    process(shared_ptr<int>(p));
    return 0;
}

// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
    // use ptr
} // ptr goes out of scope and is destroyed and count is decremented