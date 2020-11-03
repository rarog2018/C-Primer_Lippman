#include <iostream>
#include <functional>
using namespace std;

template <typename T>
int compare(const T &, const T &); // declaration

int main(void)
{
    cout << compare(11, 12) << endl;
    cout << compare(17.7, 17.7) << endl;
    cout << compare('z', 'a') << endl;
    return 0;
}

template <typename T>
int compare(const T &v1, const T &v2) // definition
{
    if (less<T>()(v1, v2))
        return -1;
    if (less<T>()(v2, v1))
        return 1;
    return 0;
}