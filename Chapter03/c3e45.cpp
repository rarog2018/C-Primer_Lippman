#include <iostream>

using namespace std;

int main()
{
    int ia[3][4] = { // three elements; each element is an array of size 4
        {0, 1, 2, 3}, // initializers for the row indexed by 0
        {4, 5, 6, 7}, // initializers for the row indexed by 1
        {8, 9, 10, 11} // initializers for the row indexed by 2
    };
    
    for (const auto &row : ia)
    {
        for(const auto col : row)
            cout << col << " ";
        cout << endl;
    }
    cout << endl;

    for (auto i = 0; i < 3; i++)
    {
        for(auto j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(const auto *pi = ia; pi != ia + 3; pi++)
    {
        for(const auto *pj = *pi; pj != (*pi) + 4; pj++)
            cout << *pj << " ";
        cout << endl;
    }

    return 0;
}
