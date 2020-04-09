#include <iostream>
#include <string>
using namespace std;

class Person
{
    // friend declarations
    friend istream &read(istream &is, Person &obj);
    friend ostream &print(ostream &os, const Person &obj);

public:
    // constructors
    Person() = default; // synthesized default constructor
    Person(string &n) : name(n) {}
    Person(string &n, string &a) : name(n), address(a) {}
    Person(istream &is);

    // member functions
    string get_name() const { return name; }
    string get_address() const { return address; }

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