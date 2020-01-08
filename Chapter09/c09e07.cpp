#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec{0, 2, 4, 6};
    // type to index vector of ints
    vector<int>::size_type iter;

    // in action
    for(iter = 0; iter != vec.size(); ++iter)
        cout << vec[iter] << " ";
}
