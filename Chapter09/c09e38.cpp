#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> iv(12, 8);
    cout << "Initial: capacity = " << iv.capacity() << " size = "
         << iv.size() << endl;

    iv.push_back(42);
    cout << "After push_back(42): capacity = " << iv.capacity() << " size = "
         << iv.size() << endl;

    for (auto it = iv.size(); it != iv.capacity(); it++)
        iv.push_back(7);
    cout << "After for loop: capacity = " << iv.capacity() << " size = "
         << iv.size() << endl;

    iv.push_back(8);
    cout << "After another push_back(8): capacity = " << iv.capacity()
         << " size = " << iv.size() << endl;

    iv.shrink_to_fit();
    cout << "After shrink_to_fit(): capacity = " << iv.capacity() << " size = "
         << iv.size() << endl;

    return 0;
}
