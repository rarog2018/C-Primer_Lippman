#include <iostream>
//using int_array = int[4];
typedef int int_array[4];
using namespace std;

int main()
{
    int ia[3][4] = { // three elements; each element is an array of size 4
        {0, 1, 2, 3}, // initializers for the row indexed by 0
        {4, 5, 6, 7}, // initializers for the row indexed by 1
        {8, 9, 10, 11} // initializers for the row indexed by 2
    };

    for (const int_array &row : ia)
    {
        for(const int col : row)
            cout << col << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(const int_array *pi = ia; pi != ia + 3; pi++)
    {
        for(const int *pj = *pi; pj != (*pi) + 4; pj++)
            cout << *pj << " ";
        cout << endl;
    }

    return 0;
}
