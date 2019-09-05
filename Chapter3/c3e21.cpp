#include <iostream>
#include <vector>
using namespace std;
void print_vector_size(const vector<vector<int>> v);
void print_vector_size(const vector<vector<string>> v);
void print_vector_content_int(const vector<vector<int>> v);
void print_vector_content_string(const vector<vector<string>> v);
int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    vector<vector<int>> v0{v1, v2, v3, v4, v5};
    vector<vector<string>> v0s{v6, v7};
    print_vector_size(v0);
    print_vector_size(v0s);
    print_vector_content_int(v0);
    print_vector_content_string(v0s);
    return 0;
}
void print_vector_size(const vector<vector<int>> v)
{
    auto it = v.begin();
    for(int i = 1; it != v.end(); it++, i++)
    {
        cout << "Size of vector v" << i << ": " << (*it).size() << endl;
    }
}
void print_vector_size(const vector<vector<string>> v)
{
    auto it = v.begin();
    for(int i = 6; it != v.end(); it++, i++)
    {
        cout << "Size of vector v" << i << ": " << (*it).size() << endl;
    }
}

void print_vector_content_int(const vector<vector<int>> v)
{
    auto it = v.cbegin();
    //this loop iterates through each element in a vector which stores vectors
    for(int i = 1; it != v.cend(); it++, i++)
    {
        cout << "Vector v" << i << ": ";
        //this loop in a loop sets 'curr' to first element in vector that 'it' currently points to
        //so every element in this vector is printed
        for(auto curr = (*it).cbegin(); curr != (*it).cend(); curr++)
            {
                cout << *curr << ", ";
            }
    cout << endl;
    }
}

void print_vector_content_string(const vector<vector<string>> v)
{
    auto it = v.cbegin();
    for(int i = 6; it != v.cend(); it++, i++)
    {
        cout << "Vector v" << i << ": ";
        for(auto curr = (*it).cbegin(); curr != (*it).cend(); curr++)
            {
                cout << *curr << ", ";
            }
    cout << endl;
    }
}
