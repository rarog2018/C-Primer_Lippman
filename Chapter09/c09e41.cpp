#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void)
{
    vector<char> chvec{'H', 'e', 'l', 'l', 'o'};
    string schv(chvec.begin(), chvec.end());
    cout << schv << endl;
    return 0;
}