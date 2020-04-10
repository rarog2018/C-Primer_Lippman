#include <iostream>
using namespace std;

class Y; // forward declaration

class X
{
    Y *ptr; // pointer to Y
};

class Y
{
    X obj; // object of type X
};

int main(void)
{
    return 0;
}