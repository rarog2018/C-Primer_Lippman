#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    string result;
    if (argc != 3)
    {
        cout << "You have to pass 2 arguments" << endl;
        return 1;
    }
    for (int i = 0; i != argc; ++i)
    {
        result += argv[i];
    }
    cout << result << endl;
    return 0;
}