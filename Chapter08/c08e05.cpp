#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read_to_vec(vector<string> &v, string fn);

int main(int argc, char *argv[])
{
    vector<string> svec;
    read_to_vec(svec, argv[1]);

    for (auto &e : svec)
    {
        cout << e << endl;
    }
    return 0;
}
void read_to_vec(vector<string> &v, string fn)
{
    string word;
    ifstream ifs(fn);
    if (ifs)
    {
        while (ifs >> word)
        {
            v.push_back(word);
        }
    }
    else
    {
        cerr << "Could not open the file" << endl;
    }
}
