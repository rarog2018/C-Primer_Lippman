#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{0, 1, 2, 3, 4};
    // according to the table '.' and '()' have the same priority
    // they are both left associative
    // then there is dereference '*' operator that is right associative
    // and then with least priority addition '+' operator L assoc.

    cout << * vec.begin() << " is equivalent to " << * ((vec.begin)()) << endl;
    cout << * vec.begin() + 1 << " is equivalent to " << (* ((vec.begin)())) + 1 << endl;

    return 0;
}
