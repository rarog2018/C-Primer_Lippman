#include <iostream>
#include <vector>

using namespace std;
void print_vec(vector<int> &vec);
int main(void)
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "ivec before fill_n: ";
    print_vec(ivec);
    fill_n(ivec.begin(), ivec.size(), 0);
    cout << "ivec after fill_n: ";
    print_vec(ivec);
    return 0;
}
void print_vec(vector<int> &vec)
{
    for (const auto &e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}