#include <iostream>
#include <string>
using namespace std;

class base
{
public:
    string name() { return basename; }
    // just prints the string inside basename
    virtual void print(ostream &os) { os << basename; }

private:
    string basename;
};
class derived : public base
{
public:
    void print(ostream &os)
    {
        // infinite recursion, because it uses the derived version of print()
        // infinitely
        // print(os);
        base::print(os); // fixes the issue
        os << " " << i;
    }

private:
    int i;
};

int main(void)
{
    base obj;
    obj.print(cout);
    cout << endl;

    derived obj2;
    obj2.print(cout);
    return 0;
}