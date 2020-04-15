#include <iostream>
#include <string>
#include <vector>
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
    C() : mem(15) {}
    NoDefault mem;
};

int main(void)
{
    // It is legal, because C has a default constructor, so vector can call it
    // and create the necessary objects
    vector<C> vec(10);

    // print the value of the index that is stored in 'mem' member of sixth
    // object stored in the vector 'vec'
    cout << vec[5].mem.index << endl;
    return 0;
}