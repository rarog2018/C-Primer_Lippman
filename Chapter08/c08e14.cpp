#include <iostream>
using namespace std;

int main(void)
{
    // "entry" and "nums" are declared as const, because we do not want to
    // change the original element of the object, they are references, because
    // we do not want to copy each string in the vector

    /*
    for (const auto &entry : people)
    {                                     // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones)
        { // for each number
            if (!valid(nums))
            {
                badNums << " " << nums; // string in badNums
            }
            else
                // ''writes'' to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())         // there were no bad numbers
            os << entry.name << " "        // print the name
               << formatted.str() << endl; // and reformatted numbers
        else                               // otherwise, print the name and bad numbers
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    */
    return 0;
}