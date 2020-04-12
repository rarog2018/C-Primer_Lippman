#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
typedef string Type; // type alias for string
Type initVal();      // global function that returns Type (which is string)
class Exercise
{
public:
    // theoretically error: redefinition of Type, but in VSC it compiles fine
    // and this definition of Type is used for the functions below
    typedef double Type;
    Type setVal(Type); // double setVale(double)
    Type initVal();    // double initVal()

private:
    int val;
};

// Type Exercise::setVal(Type parm) // error: we have to specify that we mean
// Type defined inside the class, because the declarations won't match
Exercise::Type Exercise::setVal(Type parm) // double setVal(double)
{
    val = parm + initVal();
    return val;
}

Exercise::Type Exercise::initVal()
{
    return 7;
}

Type initVal()
{
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
    Exercise obj;
    cout << obj.initVal() << endl;
    cout << obj.setVal(5) << endl;
    return 0;
}