#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(int argc, char *argv[])
{
    // exit if not enough command-line arguments
    if (argc != 2)
    {
        cerr << "Incorrect number of command-line arguments" << endl;
        return 1;
    }

    ifstream iF(argv[1]);
    // exit if failed to open the file
    if (!iF.is_open())
    {
        cerr << "Could not open the file" << endl;
        return 2;
    }

    string line, word;         // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(iF, line))
    {
        PersonInfo info;                 // create an object to hold this record's data
        istringstream record(line);      // bind record to the line we just read
        record >> info.name;             // read the name
        while (record >> word)           // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info);          // append this record to people
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