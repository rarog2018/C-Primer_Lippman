#include <iostream>
#include <vector>

using namespace std;
void compare_vec(const vector<int> &v1, const vector<int> &v2);
int main(void)
{
    vector<int> ivec1{0, 17, 99, 5, 2};
    vector<int> ivec2{0, 17, 19, 4, 87, 17};

    compare_vec(ivec1, ivec2);
}

void compare_vec(const vector<int> &v1, const vector<int> &v2)
{
    if (v1 == v2)
        cout << "Vectors are equal." << endl;
    else if (v1 < v2)
        cout << "Second vector is greater than the first." << endl;
    else
        cout << "First vector is greater than the second." << endl;
}
