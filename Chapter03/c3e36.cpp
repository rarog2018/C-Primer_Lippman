#include <iostream>
#include <vector>
using namespace std;
void compare_arrays(int a1[], int a2[], size_t ars);
void compare_vectors(vector<int> v1, vector<int> v2);
int main()
{
    int arr1[4] = {0, 1, 2, 3};
    int arr2[4] = {0, 1, 2, 3};
    int arr3[4] = {0, 2, 4, 6};
    cout << "Comparing Array1 to Array2: " << endl;
    compare_arrays(arr1, arr2, 4);
    cout << "Comparing Array1 to Array3: " << endl;
    compare_arrays(arr1, arr3, 4);

    ////////////////////////////////////////
    //// comparing vectors//////////////////
    vector<int> v1{0, 1, 2, 3};
    vector<int> v2{0, 1, 2, 3};
    vector<int> v3{0, 2, 4, 6};
    cout << "\nComparing Vector1 to Vector2: " << endl;
    compare_vectors(v1, v2);
    cout << "\nComparing Vector3 to Vector1: " << endl;
    compare_vectors(v3, v1);
    return 0;
}

// it can only compare arrays of the same size safely
// did not want to add too much complexity with checking array sizes
void compare_arrays(int a1[], int a2[], size_t ars)
{
    int *p1 = a1, *p2 = a2, *pend = p1 + ars;
    for(; p1 != pend; p1++, p2++)
    {
        if(*p1 != *p2)
        {
            cout << "Arrays are not equal. ";
            if(*p1 > *p2)
                cout << "Left array is greater than right array." << endl;
            else
                cout << "Right array is greater than left array." << endl;
            return;
        }
    }
    cout << "Arrays are equal." << endl;
}

void compare_vectors(vector<int> v1, vector<int> v2)
{
    if(v1 == v2)
        cout << "Vectors are equal." << endl;
    else
    {
        cout << "Vectors are not equal. ";
        if(v1 > v2)
            cout << "Left vector is bigger than right." << endl;
        else
            cout << "Right vector is bigger than left." << endl;
    }
}
