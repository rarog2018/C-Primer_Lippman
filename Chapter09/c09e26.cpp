#include <iostream>
#include <list>
#include <vector>

using namespace std;
int main(void)
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    list<int> ilst(begin(ia), end(ia));
    vector<int> ivec(begin(ia), end(ia));
    cout << "ilst and ivec before erase call: ";
    for (const auto &e : ia)
    {
        cout << e << " ";
    }

    // we will be checking the ilst.end() each time because the size will be
    // changing
    for (auto it = ilst.begin(); it != ilst.end(); ++it)
    {
        if ((*it) % 2)
        {
            // validate the it iterator, so it has a valid value one past the
            // element that we erased
            it = ilst.erase(it);
            // decrement it, so it again points to element before the erased
            // one because we are incrementing it anyway in for loop
            // it can be done in different ways
            --it;
        }
    }

    // here we omit the incrementation in for loop definition and move it
    // to the code inside for loop block
    for (auto it = ivec.begin(); it != ivec.end();)
    {
        if (*it % 2)
        {
            ++it;
        }
        else
        {
            it = ivec.erase(it);
        }
    }

    cout << "\nilst after the call to erase: ";
    for (const auto &e : ilst)
    {
        cout << e << " ";
    }
    cout << "\nivec after the call to erase: ";
    for (const auto &e : ivec)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}