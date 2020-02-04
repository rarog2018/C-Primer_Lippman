#include <iostream>
#include <string>
using namespace std;

struct Person
{
    // new members that return the old member's values,
    // they should be const because we do not want to change neither name nor
    // address,
    string get_name() const { return name; }
    string get_address() const { return address; }

    // old members
    string name;
    string address;
};
int main(void)
{
    Person director{"Albus Dumbledore", "Hogwarts"};
    cout << director.get_name() << ", " << director.get_address() << endl;
    return 0;
}