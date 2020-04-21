#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr);

int main(void)
{
    shared_ptr<int> p(new int(42));
    // disaster! explicitly creates an independent shared_ptr that points to
    // a memory to which p already points
    // when process function ends the new independent shared_ptr will delete
    // the object to which p points!!
    process(shared_ptr<int>(p.get()));
    cout << *p << " " << p.use_count() << endl;
    return 0;
}

// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
    cout << *ptr << endl;
    // use ptr
} // ptr goes out of scope and is destroyed and count is decremented