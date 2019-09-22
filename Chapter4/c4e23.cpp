#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s = "word";
    // error occurs because == operator has lower precedence
    // than addition operator, so without parenthesis we add
    //
    string test = s + s[s.size() - 1];
     string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
    cout << test << " " << pl << endl;
}
