#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v{0, 1, 2, 3, 4};
    auto pbeg = v.begin();
    // omits printing the value of the first element and
    // also prints the value of the element one past the
    // last element in the given vector
    while (pbeg != v.end() && *pbeg >= 0)
        cout << *++pbeg << endl;
}
