#include <iostream>

using namespace std;
int get_size();
int main(void)
{
    /*
    // backward jump over an initialized variable definition is okay
    begin:
        int sz = get_size();
        if (sz <= 0)
        {
            goto begin;
      }*/
    int sz;
    do
    {
        sz = get_size();
    } while (sz <= 0);

    // or
    while ((sz = get_size()) <= 0)
    {
        // ...
    }

    // or
    for (int sz; (sz = get_size()) <= 0;)
    {
        // ...
    }
    return 0;
}
int get_size()
{
    return 17;
}