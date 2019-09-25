#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();
    // assign values from size... 1 to the elements in ivec
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;

    for(const auto &e : ivec)
        cout << e << " ";

    cout << endl;
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for(const auto &e : ivec)
        cout << e << " ";

    // both ways give the same result, but prefix operator is
    // more efficient, because it does not create a copy of
    // its previous value,
    // we do not need this value in this case, so its better
    // to use more efficient prefix operator
}
