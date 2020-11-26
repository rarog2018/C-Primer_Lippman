#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void printContainer(const T &c)
{
    for (typename T::size_type i = 0; i != c.size(); ++i)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    string s("alpha");
    printContainer(s);

    vector<int> ivec{0, 12, 13, 11, 6, 19, 4, 22};
    printContainer(ivec);

    vector<string> svec{"Witcher", "Malazan", "LOTR", "Stormlight"};
    printContainer(svec);
    return 0;
}