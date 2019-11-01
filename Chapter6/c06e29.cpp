#include <iostream>
#include <initializer_list>

using namespace std;
int main(void)
{
    initializer_list<int> li{1, 3, 5, 7, 9, 11};
    // yes i would use a reference as the loop control variable pretty much
    // always, to avoid copying a possibly very long list, which has const
    // elements in it, so there is no risk that we will mess up with them
    for (auto &e : li) // 'e' is const int &
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}