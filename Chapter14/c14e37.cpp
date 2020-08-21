#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class AreEqual
{
public:
    // different constructors for different types
    AreEqual(int a) : val(a) {}
    AreEqual(string temp) : s(temp) {}
    AreEqual(char ch) : c(ch) {}

    // overloaded call operator definitions
    bool operator()(int rhs) { return val == rhs; }
    bool operator()(string rhs) { return s == rhs; }
    bool operator()(char rhs) { return c == rhs; }

private:
    int val;
    string s;
    char c;
};

int main(void)
{
    // lets replace characters in the string
    string toProcess("we are the champions of the world");
    replace_if(toProcess.begin(), toProcess.end(), AreEqual('e'), 'z');
    cout << toProcess << endl;

    // replace strings in the vector
    vector<string> svec{"hello", "world", "the", "show", "must", "the"};
    // now using the string constructor
    replace_if(svec.begin(), svec.end(), AreEqual("the"), "inevitable");
    for (auto &word : svec)
        cout << word << " ";
    cout << endl;

    // replace ints in the vector
    vector<int> ivec{1, 2, 3, 5, 6, 8, 2, 99, 17, 2, 16, 33};
    replace_if(ivec.begin(), ivec.end(), AreEqual(2), 77);
    for (auto &i : ivec)
        cout << i << " ";
    cout << endl;
    return 0;
}