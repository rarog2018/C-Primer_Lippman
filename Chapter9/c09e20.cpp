#include <iostream>
#include <deque>
#include <list>

using namespace std;
void print_dq(deque<int> &dq);
int main(void)
{
    int elem;
    list<int> ilst;
    deque<int> idqeven, idqodd;
    // write elements to the list
    while (cin >> elem)
    {
        ilst.push_back(elem);
    }

    // copy elements to the deques
    for (auto it = ilst.cbegin(), fin = ilst.cend(); it != fin; ++it)
    {
        if ((*it) % 2)
        {
            idqodd.push_back(*it);
        }
        else
        {
            idqeven.push_back(*it);
        }
    }

    // print elements
    print_dq(idqeven);
    print_dq(idqodd);
    return 0;
}

void print_dq(deque<int> &dq)
{
    for (const auto &elem : dq)
    {
        cout << elem << " ";
    }
    cout << endl;
}