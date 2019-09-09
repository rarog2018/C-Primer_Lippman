#include <iostream>
#include <string>
using namespace std;

string sa[10];          // 10 empty strings
int ia[10];             // 10 ints of value 0
int main()
{
    string sa2[10];     // 10 empty strings
    int ia2[10];        // 10 ints of undefined value
    for(auto el : ia2)
    {
        cout << el << ", ";
    }
    return 0;
}
