#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<string> svec1{"Witcher", "LOTR", "Malazan"};
    vector<string> svec2{"Stormlight", "WOT", "ASOIAF"};

    // applies the built-in char operator
    bool a = "cobble" == "stone";
    // also applies the string == operator (Witcher == Stormlight)
    bool b = svec1[0] == svec2[0];
    // applies the vector == operator
    bool c = svec1 == svec2;
    // applies the string == operator (Witcher == stone)
    bool d = svec1[0] == "stone";
    return 0;
}