#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<int, int> m;                           // empty map m
    cout << "size of m: " << m.size() << endl; // prints 0
    // searches the map 'm' for the key '0', because it is not in the map
    // it is added with value 0, then the value 1 is assigned to it
    m[0] = 1;
    // so now the map has one key '0' which has a value '1'
    cout << "size of m: " << m.size() << endl;
    cout << m[0] << endl; // prints 1
    return 0;
}