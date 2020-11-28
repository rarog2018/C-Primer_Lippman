#include <iostream>
#include <memory>
using namespace std;

// function-object class
class DebugDelete
{
public:
    DebugDelete(ostream &s = cerr) : os(s){};

    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting pointer with value " << *p << endl;
        delete p;
    }

private:
    ostream &os;
};

int main(void)
{
    DebugDelete d;

    // this will be deleted at the end of the program, we do not need our 'd'
    // object it can be a temporary object created with DebugDelete()
    unique_ptr<string, DebugDelete> sup(new string("Witcher"), d);

    int *ip = new int(22);
    *ip += 10;
    d(ip); // prints the message and deletes the pointer

    float *fp = new float(173.21);
    d(fp);
    return 0;
}