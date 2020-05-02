#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

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

    string word, line;
    vector<string> svec;
    // store each line in a vector
    while (getline(iF, line))
    {
        svec.push_back(line);
    }

    // use istringstream to read each element from the vector a word at a time
    for (auto &e : svec)
    {
        istringstream isS(e); // bind element to the isS
        while (isS >> word)   // read each word in a line
        {
            cout << word << " "; // and print it
        }
        cout << endl;
    }
    return 0;
}