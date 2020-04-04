#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_ivec(vector<int> &v, int n);
void print_svec(vector<string> &v, int n);
int main(void)
{
    /////////////////////////           a           ///////////////////////
    vector<int> v1; // 0 elements
    print_ivec(v1, 1);

    /////////////////////////           b           ///////////////////////
    vector<int> v2(10); // 10 elements, value 0
    print_ivec(v2, 2);

    /////////////////////////           c           ///////////////////////
    vector<int> v3(10, 42); // 10 elements, value 42
    print_ivec(v3, 3);

    /////////////////////////           d           ///////////////////////
    vector<int> v4{10}; // 1 element, value 10
    print_ivec(v4, 4);

    /////////////////////////           e           ///////////////////////
    vector<int> v5{10, 42}; // 2 elements, values 10 and 42
    print_ivec(v5, 5);

    /////////////////////////           f           ///////////////////////
    vector<string> v6{10}; // 10 element, value: empty string, because 10 is
    // an int and it cannot be used to list initialize the vector, so instead
    // it uses that int to construct 10 empty strings
    print_svec(v6, 6);

    /////////////////////////           g           ///////////////////////
    vector<string> v7{10, "hi"}; // 10 elements, value "hi"
    print_svec(v7, 7);

    return 0;
}

void print_ivec(vector<int> &v, int n)
{
    cout << "Vector " << n << ", size: " << v.size() << ", contents: ";
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << "\n"
         << endl;
}
void print_svec(vector<string> &v, int n)
{
    cout << "Vector " << n << ", size: " << v.size() << ", contents: ";
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << "\n"
         << endl;
}