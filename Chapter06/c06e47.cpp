#include <iostream>
#include <vector>

using namespace std;
void print_vec(vector<int> &vec, size_t n);
int main(void)
{
    vector<int> ivec{1, 3, 5, 7, 9, 11};
    print_vec(ivec, 0);
    return 0;
}

void print_vec(vector<int> &vec, size_t n)
{
#ifndef NDEBUG
    cerr << __func__ << ": vector size is " << vec.size() << endl;
#endif
    // base case
    if (n == vec.size())
    {
        return;
    }
    // recursive case
    cout << vec[n] << " ";
    print_vec(vec, n + 1);
}