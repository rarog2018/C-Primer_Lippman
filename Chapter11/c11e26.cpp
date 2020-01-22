#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    // map's key_type can be used to subscript a map
    // map<key_type, mapped_type> amap;
    // amap[key] returns the map's mapped_type
    map<string, int> simap{{"hello", 15}, {"world", 30}};
    // as we can see map's key_type is indeed a string
    map<string, int>::key_type lmao = "ayy lmao";
    simap[lmao] = 59;
    // and subscript operator used on map indeed returns its mapped_type
    map<string, int>::mapped_type ival = simap["world"];
    cout << "simap[lmao] = " << simap[lmao] << endl; // 59
    cout << "ival = " << ival << endl;               // 30

    // subscript operator cannot be used on a const map regarldes of what key
    // type we us
    const map<string, int> siconstmap;
    // siconstmap["hello"];    // error
    return 0;
}