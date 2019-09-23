#include <iostream>
#include <vector>

using namespace std;
bool is_value_in_range(vector<int>::const_iterator start, vector<int>::const_iterator finish, int number);
int main(void)
{
    vector<int> vec{0, 2, 4, 6, 7, 9, 11, 12, 14};
    auto it = vec.cbegin();
    // set the range
    auto itb = it + 2, ite = it + 6;
    if(is_value_in_range(itb, ite, 11))
        cout << "The value is in the range." << endl;
    else
        cout << "The value is not in the range." << endl;
}

// a function that takes a pair of iterators to a vector<int> and an int value
// it checks whether the value is in given range and returns bool
bool is_value_in_range(vector<int>::const_iterator start, vector<int>::const_iterator finish, int number)
{
    while(start != finish)
    {
        if(*start == number)
            return true;
        ++start;
    }
    return false;
}
