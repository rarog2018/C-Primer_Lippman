#include <iostream>
using namespace std;

class NoDefault
{
public:
    NoDefault(int i) : index(i) {}
    int index;
};

class C
{
public:
    C() : mem(0) {}
    NoDefault mem;
};

int main(void)
{
    C obj;
    cout << obj.mem.index << endl;
    return 0;
}