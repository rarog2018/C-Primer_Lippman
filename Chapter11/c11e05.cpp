#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(void)
{
    map<int, double> idmap;
    set<int> iset;
    /*
    When we define map we need to specify both the key and the value type.
    In set element type is the key type.
    
    When we need a data structure that can hold both key and its value like
    for example a dictionary, we should use a map. 
    When we just need the key for example to quickly lookup if its present
    we should use a set.
    */
    return 0;
}