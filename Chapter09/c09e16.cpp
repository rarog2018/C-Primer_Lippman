#include <iostream>
#include <vector>
#include <list>

using namespace std;
void compare_lst_to_vec(list<int> &li, vector<int> &v);
int main(void)
{
    list<int> ilist{0, 17, 19, 5, 2};
    vector<int> ivec{0, 17, 19, 5, 2, 17};

    compare_lst_to_vec(ilist, ivec);
}

void compare_lst_to_vec(list<int> &li, vector<int> &v)
{
    // iterators
    list<int>::const_iterator itli = li.cbegin();
    list<int>::const_iterator itle = li.cend();
    vector<int>::const_iterator itv = v.cbegin();
    vector<int>::const_iterator itve = v.cend();

    for (; (itli != itle) && (itv != itve); ++itli, ++itv)
    {
        if ((*itli) == (*itv))
            continue;
        else if ((*itli) < (*itv))
        {
            cout << "Vector is greater than the list." << endl;
            return;
        }
        else
            cout << "List is greater than the vector." << endl;
            return;
    }
    // i could use size but i already spent 4 lines for these iterators
    if ((itli == itle) && (itv == itve))
        cout << "Vector and list are equal." << endl;
    else if (itli != itle)
        cout << "List is greater than the vector." << endl;
    else
        cout << "Vector is greater than the list." << endl;
}
