#include <iostream>
#include <forward_list>
#include <string>

using namespace std;
void insert_into_flist(forward_list<string> &flst, string a, string b);
int main(void)
{
    forward_list<string> flst{"Hello", "world", "cats", "dogs", "turtles"};
    string a = "cat", b = "mutants";

    insert_into_flist(flst, a, b);
    cout << endl;
    for (const auto &e : flst)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

void insert_into_flist(forward_list<string> &flst, string a, string b)
{
    auto prev = flst.before_begin(), curr = flst.begin();
    for (auto fin = flst.end(); curr != fin; ++curr)
    {
        if (*curr == a)
        {
            curr = flst.insert_after(curr, b);
            return;
        }
        prev = curr;
    }
    flst.insert_after(prev, b);
}