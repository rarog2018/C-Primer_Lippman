#include <iostream>
#include "c07Sales_data.h"
using namespace std;

// in read() the reference to Sales_data object is plain, because the function
// changes the values of the object's members
// in print() the reference to Sales_data object is const because the function
// does not change the object's data (and should not)
istream &read(istream &is, Sales_data &obj);
ostream &print(ostream &os, const Sales_data &obj);

int main(void)
{
    return 0;
}