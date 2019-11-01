#include <iostream>
#include <string>
using namespace std;

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    // the type of elem is const string & => a reference to const string
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}
int main(void)
{
    initializer_list<string> il{"rntime", "critical", "out of range"};
    return 0;
}