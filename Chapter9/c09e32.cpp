#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            // it is illegal, because it is undefined what will be evaluated
            // first
            // iter = vi.insert(iter, *iter++);
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            iter = vi.erase(iter);
    }
    for (const auto &e : vi)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}