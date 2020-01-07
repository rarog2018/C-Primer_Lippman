#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;
int main(void)
{
    string filename;            // store filename
    cout << "Enter filename: "; // prompt for filename
    cin >> filename;            // read filename from cin

    fstream afile(filename); // create fstream object
    if (afile.is_open())     // check if file opened successfuly
    {
        // reads string values from input stream, which is a file
        istream_iterator<string> in(afile), eof;
        vector<string> svec(in, eof); // just a vector
        // writes string values to cout followed by newline
        ostream_iterator<string> out_fs(cout, "\n");
        // print the values in the vector
        copy(svec.begin(), svec.end(), out_fs);
    }
    else
    {
        cerr << "Could not open the file" << endl;
    }
    return 0;
}