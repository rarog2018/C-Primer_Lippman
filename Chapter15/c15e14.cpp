#include <iostream>
#include <string>
using namespace std;

class base
{
public:
    string name()
    {
        cout << "Using base::name() ";
        return basename;
    }
    // just prints the string inside basename
    virtual void print(ostream &os)
    {
        cout << "Using base::print() ";
        os << basename;
    }

private:
    string basename = "basename";
};
class derived : public base
{
public:
    void print(ostream &os)
    {
        // infinite recursion, because it uses the derived version of print()
        // infinitely
        // print(os);
        cout << "Using derived::print() ";
        base::print(os); // fixes the issue
        os << " " << i;
    }

private:
    int i = 17;
};

int main(void)
{
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    // a)
    bobj.print(cout); // calls the base::print()
    cout << endl;

    // b)
    dobj.print(cout); // calls derived::print() in which it calls base::print()
    cout << endl;

    // c)
    cout << bp1->name() << endl; // calls base::name()

    // d)
    cout << bp2->name() << endl; // calls base::name()

    // e)
    br1.print(cout); // calls base::print()
    cout << endl;

    // f)
    br2.print(cout); // calls derived::print() then base::print()
    cout << endl;
    return 0;
}