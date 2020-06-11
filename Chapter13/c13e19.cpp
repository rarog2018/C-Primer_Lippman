#include <iostream>
#include <string>
using namespace std;

// Yes, this class needs to define its own versions of copy-control members,
// because otherwise the id from one object will be copied to another, hence
// it won't be unique anymore
class Employee
{
public:
    // constructors
    Employee() : empId(++idVal) {}
    Employee(const string &name) : empName(name), empId(++idVal) {}

    // copy-control members
    // i used explicit on copy constructor to prevent using it = operator
    // i deleted = operator to prevent assignment, because empId is const,
    // so i wouldn't be able to give it a value outisde of initialization
    explicit Employee(const Employee &o) : empName(o.empName), empId(++idVal) {}
    Employee &operator=(const Employee &rhs) = delete;

    // other members
    void print() { cout << this->empName << " " << this->empId << endl; }

private:
    string empName;
    const unsigned empId;
    static unsigned idVal;
};

unsigned Employee::idVal = 0;

int main(void)
{
    Employee a("Wiedzmin"), b("Tolkien"), c;
    a.print();
    b.print();
    c.print();

    Employee d(a);
    // Employee e = b;  // error, thanks to explicit copy-constructor and deleted
    // = operator
    d.print();
    // e.print();
    return 0;
}