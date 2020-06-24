#include <iostream>
using namespace std;

// the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion
// loop, because swap calls either std::swap or type specific version of swap
// the type specific version of swap swap(HasPtr&, HasPtr&) in its code block
// calls the std::swap for each swapped member, not the swap(HasPtr&, HasPtr&)

int main(void)
{
    return 0;
}