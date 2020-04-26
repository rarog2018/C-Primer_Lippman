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
    string line;
    ifstream ifs(fn);
    if (ifs)
    {
        while (getline(ifs, line))
        {
            v.push_back(line);
        }
    }
    else
    {
        cerr << "Could not open the file" << endl;
    }
}
