#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    // vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi = {1, 3, 5, 7, 9};
    auto iter = vi.begin();
    // infinite loop, if *iter is even then we will just ininitely go between
    // while and if statement, vector will remain untouched
    // if *iter is odd then we will pass the if condition then insert value
    // of iter before iter and assign iter to iterator that points to this new
    // value, because the value is odd we will repeat this infinitely
    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
    ++iter;
    return 0;
}