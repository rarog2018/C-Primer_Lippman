#include <iostream>
using namespace std;

// in this case i do not see why i would use 'do ... while' instead of while,
// because the condition is 'true', so it will execute at least once to the
// same point as do...while
/*
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    do
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q")
            break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    } while(true);
}
*/
int main(void)
{
    return 0;
}