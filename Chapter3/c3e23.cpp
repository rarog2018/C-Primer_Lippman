#include <iostream>
#include <vector>
#include <string>
using namespace std;
void double_the_values(vector<int> &v);
void print_vector(vector<int> v);

int main()
{
    vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    double_the_values(v1);
    print_vector(v1);
    return 0;
}

void double_the_values(vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        *it *= 2;
    }
}

void print_vector(vector<int> v)
{
    for(auto it = v.cbegin(); it != v.cend(); it++)
    {
        cout << *it << " ";
    }
}
