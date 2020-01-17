#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{

    map<string, size_t> word_count;
    // auto map_it = word_count.cbegin();   // with auto
    map<string, size_t>::const_iterator map_it = word_count.cbegin(); // without

    return 0;
}