#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
void print_family_map(map<string, vector<pair<string, string>>> &fm);

int main(void)
{
    // map that key is a string and value is a vector of strings
    map<string, vector<pair<string, string>>> familyChildrenNames;
    string family, childName, birthday; // variables for family, childs names and birthdays

    // initial vectors with children names
    vector<pair<string, string>> childrenNames1{{"Anna", "01-01-2000"}, {"Casper", "05-05-2005"}, {"Tom", "09-09-2009"}}, childrenNames2{{"Lily", "01-11-2011"}, {"Frodo", "11-15-2015"}};

    // initial entry
    familyChildrenNames = {{"Colos", childrenNames1}, {"Baggins", childrenNames2}};

    // print initial values
    cout << "Initial family map: " << endl;
    print_family_map(familyChildrenNames);

    // further entries
    while (cin >> family)
    {
        // until cin is valid and birthday is not a comma
        while (cin >> childName >> birthday && birthday != ",")
        {
            // push_back child's name to its family, if the family entry is
            // not in the map already it gets created
            familyChildrenNames[family].push_back({childName, birthday});
        }
    }

    cout << "\nFinal result:" << endl;
    print_family_map(familyChildrenNames);
    return 0;
}

// takes a map as a parameter
void print_family_map(map<string, vector<pair<string, string>>> &fm)
{
    // loop through every single pair in family name map
    for (const auto &p : fm)
    {
        // print the family name (the key)
        cout << p.first << ": ";
        // loop through every single element of pairs value, which in this case
        // is a vector of strings
        for (const auto vecPair : p.second)
        {
            // print each string in the vector
            cout << vecPair.first << " " << vecPair.second << " ";
        }
        cout << endl;
    }
}