#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;
void write_to_stream(int i, ostream_iterator<int> &o1, ostream_iterator<int> &o2);
int main(void)
{
    string inFileN, oFileN1, oFileN2;     // store filenames
    cout << "Enter filenames: ";          // prompt for filenames
    cin >> inFileN >> oFileN1 >> oFileN2; // read filenames from cin

    // create fstream objects
    fstream iFil(inFileN, ofstream::in);
    fstream oFil1(oFileN1, ofstream::out), oFil2(oFileN2, ofstream::out);
    // check if files opened successfuly
    if (iFil.is_open() && oFil1.is_open() && oFil2.is_open())
    {
        // reads int values from input stream, which is a file
        istream_iterator<int> in(iFil), eof;
        // writes int values to first file followed by space
        ostream_iterator<int> oodd(oFil1, " ");
        // writes int values to second file followed by newline
        ostream_iterator<int> oeven(oFil2, "\n");

        // use for_each algorith to proceed each element using lambda
        // for_each(in, eof, [&](int i) { (i % 2) ? oodd = i : oeven = i; });
        // maybe easier using bind, at least more readable for me
        for_each(in, eof, bind(write_to_stream, _1, oodd, oeven));
    }
    else
    {
        cerr << "Could not open the file" << endl;
    }
    return 0;
}
void write_to_stream(int i, ostream_iterator<int> &o1, ostream_iterator<int> &o2)
{
    if (i % 2)
    {
        o1 = i;
    }
    else
    {
        o2 = i;
    }
}