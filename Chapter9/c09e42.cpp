#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    char c;
    string s1 = "";
    // this should improve the performance of the program because the string will
    // be reallocated fewer times
    // i am using unix 'time' program to check the performance
    // s1.reserve(1000000);
    s1.reserve(100);
    auto curr = s1.capacity();            // this line was not included in tests
    cout << "Capacity = " << curr << " "; // not included in tests
    // for(size_t i = 0; i != 1000002; ++i)
    for (size_t i = 0; i != 102; ++i)
    {
        c = 65 + (i % 26);
        s1 += c;
        auto temp = s1.capacity(); // not included in tests
        if (curr != temp)          // not included in tests
        {
            curr = temp;
            cout << curr << " ";
        }
    }
    cout << endl; // not included in tests
    // cout << s1 << endl;
    // after couple runs i see that the version without reserve has biger
    // difference in performance comparing to the version with reserve which
    // is interesting considering that i am not loading milions of characters
    // but just around 100
    // the results with reserve look pretty much the same every time
    // without reserve and prints         with reserve, without prints
    // real    0m0,355s  -  0m0,526s           0m0,286s  -  0m0,401s
    // user    0m0,015s  -  0m0,031s           0m0,015s  -  0m0,031s
    // sys     0m0,015s  -  0m0,047s           0m0,015s  -  0m0,031s

    // printing the result seems to have no impact at all

    // after further tests, there seem to be no difference between operating
    // on 100 or 1 milion characters, the times stay pretty much the same,
    // although every time the reserve version has better and closer to each
    // other results
    return 0;
}