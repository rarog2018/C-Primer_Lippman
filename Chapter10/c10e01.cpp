#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    vector<int> ivec;
    int element, value;
    cout << "Type some integer numbers: ";
    // store integers in a vector
    while (cin >> element)
    {
        ivec.push_back(element);
    }
    cout << "Type integer value: ";
    cin.clear();
    fflush(stdin);
    cin >> value;
    // process ivec from begining to the end and count how many times a given
    // value occured
    cout << value << " occurs " << count(ivec.cbegin(), ivec.cend(), value)
         << " times." << endl;
    return 0;
}
