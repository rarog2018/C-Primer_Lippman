#include <iostream>
#include <initializer_list>

using namespace std;
int sum_of_ilst(initializer_list<int> li);
int main(void)
{
    initializer_list<int> li{1, 3, 5};
    cout << "Sum of the elements in initializer list: " << sum_of_ilst(li) << endl;
    return 0;
}
int sum_of_ilst(initializer_list<int> li)
{
    int result = 0;
    for (auto &el : li)
    {
        result += el;
    }
    return result;
}