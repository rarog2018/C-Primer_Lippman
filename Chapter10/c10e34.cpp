#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto rev_it = ivec.crbegin(); rev_it != ivec.crend(); ++rev_it)
    {
        cout << *rev_it << " ";
    }
    cout << endl;
    return 0;
}