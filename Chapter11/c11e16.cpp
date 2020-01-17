#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<char, int> chimap{{'c', 14}, {'a', 12}, {'b', 13}};
    auto map_it = chimap.find('a');
    map_it->second = 15;
    cout << map_it->first << " " << map_it->second << endl;
    return 0;
}