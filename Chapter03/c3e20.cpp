#include <iostream>
#include <vector>
using namespace std;

// helper functions
void print_adjacent_sum(vector<int> v);
void print_first_last_sum(vector<int> v);

int main(void)
{
    vector<int> ivec;
    int a;

    // read a set of integers into a vector
    while (cin >> a)
    {
        ivec.push_back(a);
    }

    // print the sum of each pair of adjacent elements
    print_adjacent_sum(ivec);

    // print the sum of the first and last elements followed by the sum
    // of the second and second-to-last elements and so on
    print_first_last_sum(ivec);

    return 0;
}

void print_adjacent_sum(vector<int> v)
{
    // loop up to the second-to-last element
    for (vector<int>::size_type i = 0; i != v.size() - 1; ++i)
    {
        cout << v[i] + v[i + 1] << " ";
    }
    cout << endl;
}

void print_first_last_sum(vector<int> v)
{
    // determine the middle index
    vector<int>::size_type max = v.size() - 1;
    vector<int>::size_type mid = max / 2;

    // loop up to the middle element
    for (vector<int>::size_type i = 0; i != mid + 1; ++i)
    {
        // if element in the middle has no pair
        if (i == max - i)
        {
            cout << v[i] << endl;
        }
        else
        {
            cout << v[i] + v[max - i] << " ";
        }
    }
}