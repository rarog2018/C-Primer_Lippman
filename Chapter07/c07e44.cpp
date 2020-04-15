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

int main(void)
{
    // It is illegal, it tries to create 10 value initialized NoDefault
    // objects and store them in the vector. NoDefault does not have a default
    // constructor so the vector cannot call it to construct these objects,
    // hence it won't compile.
    vector<NoDefault> vec(10);
    return 0;
}