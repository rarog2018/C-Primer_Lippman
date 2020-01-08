#include <iostream>
#include <vector>

using namespace std;
vector<int>::const_iterator is_value_in_range(vector<int>::const_iterator start,
                       vector<int>::const_iterator finish, int number);
int main(void)
{
    int val = 7;
    vector<int> vec{0, 2, 4, 6, 7, 9, 11, 12, 14};
    auto it = vec.cbegin();
    // set the range
    auto itb = it + 2, ite = it + 6;
    // assign returned iterator to result
    auto result = is_value_in_range(itb, ite, val);
    // if result is not ite (which is exclusive of our range)
    if(result != ite)
        cout << "The value " << val << " is in the range at index "
            << result - it << endl;
    else
        cout << "The value is not in the range." << endl;
}

// a function that takes a pair of iterators to a vector<int> and an int value
// it checks whether the value is in given range and returns iterator to this value
vector<int>::const_iterator is_value_in_range(vector<int>::const_iterator start,
                       vector<int>::const_iterator finish, int number)
{
    while(start != finish)
    {
        if(*start == number)
            return start;
        ++start;
    }
    return finish;
}

