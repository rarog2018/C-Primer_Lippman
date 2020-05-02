#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// members are public by default; see § 7.2 (p. 268)
struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(void)
{
    string line, word;         // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    istringstream record;      // declare istringstream object
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line))
    {
        record.str(line); // we have to use str() to copy the string into record
        PersonInfo info;  // create an object to hold this record's data
        // istringstream record(line);      // bind record to the line we just read
        record >> info.name;             // read the name
        while (record >> word)           // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info);          // append this record to people
        record.clear();                  // reset record
    }

    // check if it worked
    for (auto &person : people)
    {
        cout << person.name << " ";
        for (auto &phone : person.phones)
        {
            cout << phone << " ";
        }
        cout << endl;
    }
    return 0;
}