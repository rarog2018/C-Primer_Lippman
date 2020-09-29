#include <iostream>
using namespace std;

// Copy: when the object of type Query is copied it uses:
// Query(std::shared_ptr<Query_base> query) : q(query) {}
// which copies the shared_ptr q member, so the new Query object shares the
// memory with the original Query object, the reference count is incremented

// Move: it uses synthesized move constructor, which moves the shared_ptr q
// member, so the new Query object points to the memory to which the original
// object pointed, and the original pointer is destroyed (it does not point, to
// that memory anymore)

// Assign: uses the synthesized copy assign, which does the same as the copy
// constructor

// Destroy: uses the synthesized destructor, which uses the shared_ptr destructor
// which decrements the reference count. If it gets to 0 the memory used by the
// shared_ptr will get deallocated and destroyed

int main(void)
{
    return 0;
}