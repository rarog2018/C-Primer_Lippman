#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee() : empId(++idVal) {}
    Employee(const string &name) : empName(name), empId(++idVal) {}
    static unsigned idVal;
    void print() { cout << this->empName << " " << this->empId << endl; }

private:
    string empName;
    const unsigned empId;
};

unsigned Employee::idVal = 0;

int main(void)
{
    Employee a("Wiedzmin"), b("Tolkien"), c;
    a.print();
    b.print();
    c.print();
    return 0;
}