#include <iostream>

using namespace std;
void print(const int *a);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
void print(int (&arr)[2]);
int main(void)
{
    int i = 0, j[2] = {0, 1};
    print(&i);

    print(begin(j), end(j));
    print(j, 2); // equivalent to print(j, begin(j) - end(j));
    print(j);
    return 0;
}

void print(const int *a)
{
    cout << *a << endl;
}

void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
    {
        cout << *beg++ << " "; // print the current element
        // and advance the pointer
    }
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << " ";
    }
    cout << endl;
}

void print(int (&arr)[2])
{
    for (auto elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
}