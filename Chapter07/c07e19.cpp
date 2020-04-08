#include <iostream>
#include <string>
using namespace std;

class Person
{
    // constructors and get_name(), get_address() should public,
    // because we want to create the objects and collect the data about them
    // anywhere in the program
    // they are parts of the interface
public:
    // constructors
    Person() = default; // synthesized default constructor
    Person(string &n) : name(n) {}
    Person(string &n, string &a) : name(n), address(a) {}
    Person(istream &is);

    // member functions
    string get_name() const { return name; }
    string get_address() const { return address; }

    // name and address should be encapsulated, so the programmer has the control of
    // how the user can approach data inside these members f.e user can be forced
    // to use a particular format or values of the data inside these members
    // we can write a function that does that and make the user use it
    // they are a part of implenentation
private:
    // member attributes
    string name;
    string address;
};

// nonmember functions to input and output the data from the object's
istream &read(istream &is, Person &obj);
ostream &print(ostream &os, const Person &obj);

int main(void)
{
    return 0;
}
// constructor definition
Person::Person(istream &is)
{
    read(is, *this);
}
//////////////////////////////////////////////////////////////////////////////

// read the data into given Person object from the given stream
istream &read(istream &is, Person &obj)
{
    getline(is, obj.name);
    getline(is, obj.address);
    return is;
}

// print the data from the given Person object on to given stream
ostream &print(ostream &os, const Person &obj)
{
    os << obj.get_name() << " " << obj.get_address();
    return os;
}