#include <iostream>
using namespace std;

// If we use 'class' the members before the first access specifier are private
// If we use 'struct' these members are public

class Gibberish
{
    int index = 1; // this member is private by default
public:
    double val = 2;
};

struct NotGibberish
{
    int index = 3; // this member is public by default
private:
    double val = 4;
};

int main(void)
{
    Gibberish obj1;
    NotGibberish obj2;
    cout << obj1.val << " " << obj2.index << endl; // ok public members
    // cout << obj1.index << " " << obj2.val << endl; // error, private members

    return 0;
}