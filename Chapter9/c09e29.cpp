#include <iostream>
#include <vector>

using namespace std;
void print_vec(vector<int> &vec);
int main(void)
{
    vector<int> ivec(25, 17);
    print_vec(ivec);
    // vec.resize(100), changes size of a vector to 100 elements in our case
    // 75 new value initialized (0) elements will be added
    ivec.resize(100);
    print_vec(ivec);
    // vec.resize(10), changes size of a vector to 10 elements in our case
    // 90 elements from the back of the vector will be erased
    ivec.resize(10);
    print_vec(ivec);
    return 0;
}

void print_vec(vector<int> &vec)
{
    int i = 0;
    cout << "Vector: \n";
    for (const auto &e : vec)
    {
        ++i;
        cout << e << " ";
        if (!(i % 25))
        {
            cout << endl;
        }
    }
    cout << endl;
}