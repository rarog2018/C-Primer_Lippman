#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main(void)
{
    string ascdescenders("tdfhklbqypgji"), line, word, largestOccur = "";
    ifstream abcfile("abc.txt");
    if (abcfile)
    {
        while (getline(abcfile, line))
        {
            istringstream read(line);
            while (read >> word)
            {
                if (word.find_first_of(ascdescenders) == string::npos && word.size() > largestOccur.size())
                {
                    largestOccur = word;
                }
            }
        }
    }
    else
    {
        cerr << "Could not open the file" << endl;
    }
    abcfile.close();
    cout << "The largest word in the text file that contains neither ascenders"
            " nor descenders is : "
         << largestOccur << endl;
    return 0;
}