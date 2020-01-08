#include <iostream>

using namespace std;
int absolute(int n);
int main(void)
{
    int numbers[]{12, 15, -99, -200, 55, -2499};
    for (const auto &e : numbers)
    {
        cout << absolute(e) << " ";
    }
    cout << endl;
    return 0;
}
int absolute(int n)
{
    if (n > 0)
    {
        return n;
    }
    else
    {
        return -n;
    }
}