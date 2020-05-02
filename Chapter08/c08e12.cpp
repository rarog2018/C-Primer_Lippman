#include <iostream>
#include <string>
#include <vector>
using namespace std;

// We do not need in-class initializers, because string is by default initialized
// to an empty string, and vector can be expanded at any time with push_back()
struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(void)
{
    return 0;
}