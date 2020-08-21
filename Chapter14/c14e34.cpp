#include <iostream>
#include <string>
using namespace std;

class IfThenElse
{
public:
    string operator()(bool a, string b = "true", string c = "false") const
    {
        return a ? b : c;
    }
};

int main(void)
{
    IfThenElse ob;
    // pass an expression that can be converted to bool to the object
    cout << ob(5 < 7) << endl;
    cout << ob((17 < 2), "yup", "nope") << endl;
    cout << ob(("witcher" != "malazan")) << endl;
    return 0;
}