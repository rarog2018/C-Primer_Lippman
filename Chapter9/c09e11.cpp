#include <iostream>
#include <vector>

using namespace std;
void print_vec(vector<int> &v);
int main(void)
{
    vector<int> v1;         // empty vector
    vector<int> v2(10, 1);     // 10 elements of value 1
    vector<int> v3{10};     // 1 element of value 10
    vector<int> v4(v2);     // 10 elements of value 1 (as in v2)
    vector<int> v5 = v1;    // empty vector
    vector<int> v6 = {2, 4};// 2 elements of values 2, 4
    vector<int> v7(v6.cbegin(), v6.cend()); // same as v6

    cout << "v1: "; print_vec(v1);
    cout << "v2: "; print_vec(v2);
    cout << "v3: "; print_vec(v3);
    cout << "v4: "; print_vec(v4);
    cout << "v5: "; print_vec(v5);
    cout << "v6: "; print_vec(v6);
    cout << "v7: "; print_vec(v7);
}

void print_vec(vector<int> &v)
{
    for(const auto &e : v)
        cout << &e << " ";
    cout << endl;
}
