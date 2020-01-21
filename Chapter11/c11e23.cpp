#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
void print_family_map(multimap<string, vector<string>> &fm);

int main(void)
{
    // multimap that key is a string and value is a vector of strings
    multimap<string, vector<string>> familyChildrenNames;
    string family, childName; // variables for family and childs names

    // initial vectors with children names
    vector<string> childrenNames1{"Anna", "Casper", "Tom"},
        childrenNames2{"Lily", "Frodo"};
    // initial entry
    familyChildrenNames = {{"Colos", childrenNames1}, {"Baggins", childrenNames2}};

    // print initial values
    cout << "Initial family map: " << endl;
    print_family_map(familyChildrenNames);

    // further entries
    while (cin >> family)
    {
        // until cin is valid and childName is not a comma
        while (cin >> childName && childName != ",")
        {
            // push_back child's name to its family, if the family entry is
            // not in the map already it gets created
            auto it = familyChildrenNames.find(family);
            if (it != familyChildrenNames.end())
            {
                it->second.push_back(childName);
            }
            else
            {
                // always adds new key
                familyChildrenNames.insert({family, {childName}});
            }
        }
    }

    cout << "\nFinal result:" << endl;
    print_family_map(familyChildrenNames);
    return 0;
}

// takes a map as a parameter
void print_family_map(multimap<string, vector<string>> &fm)
{
    // loop through every single pair in family name map
    for (const auto &p : fm)
    {
        // print the family name (the key)
        cout << p.first << ": ";
        // loop through every single element of pairs value, which in this case
        // is a vector of strings
        for (const auto ch : p.second)
        {
            // print each string in the vector
            cout << ch << " ";
        }
        cout << endl;
    }
}