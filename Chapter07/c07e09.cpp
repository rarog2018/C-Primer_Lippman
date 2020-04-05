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

// nonmember functions to input and output the data from the object's
istream &read(istream &is, Person &obj);
ostream &print(ostream &os, const Person &obj);

int main(void)
{
    Person director;
    read(cin, director);
    print(cout, director);
    return 0;
}

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