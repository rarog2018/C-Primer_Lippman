#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // count(key) is useful when we want to know how many entries of the given
    // key are present in the container - this applies to multimaps and multisets
    // not particularly useful for unique-key-only containers

    // find(key) is useful when we want to know if the element is present in
    // the container - especially applies to unique-key-only containers like map
    // (especially because [] operator adds an element to the map)
    return 0;
}