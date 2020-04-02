#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ///////////////////         a           ////////////////////////
    // legal, it creates an empty vector of vectors of type int
    vector<vector<int>> ivec;

    ///////////////////         b           ////////////////////////
    // illegal, it tries to copy an vector<vector<int>> to a vector
    // of strings,
    // vector<string> svec = ivec;

    ///////////////////         c           ////////////////////////
    // legal, it creates a vector of strings and initializes it with
    // ten strings "null"
    vector<string> svec(10, "null");
    for (auto &e : svec)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}