#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class MatchBound
{
public:
    // constructor
    MatchBound(int mn, int mx) : minSize(mn), maxSize(mx) {}

    // call operator
    bool operator()(const string &s) const
    {
        return (s.size() >= minSize) && (s.size() <= maxSize);
    }

private:
    int minSize;
    int maxSize;
};

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Not enough arguments";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        cerr << "Failed to open the file ";
        return 2;
    }

    MatchBound boundaries(1, 10);
    string line, word;
    int counter = 0;
    while (getline(inputFile, line))
    {
        istringstream strm(line);
        while (strm >> word)
        {
            if (boundaries(word))
                ++counter;
        }
    }

    cout << "There were " << counter << " words in given boundaries" << endl;
    inputFile.close();
    return 0;
}