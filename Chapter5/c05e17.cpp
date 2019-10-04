#include <iostream>
#include <vector>

using namespace std;
bool is_prefix(const vector<int> &v1, const vector<int> &v2);
void fill_vector(vector<int> &v1);
size_t smaller_size(const vector<int> &v1, const vector<int> &v2);
int main(void)
{
    int val;
    vector<int> ivec1, ivec2;
    fill_vector(ivec1);
    fill_vector(ivec2);
    cout << ((is_prefix(ivec1, ivec2)) ? "True" : "False") << endl;
    return 0;
}

// straightforward just fill the vector with given input
void fill_vector(vector<int> &v1)
{
    int val;
    cin.clear();
    fflush(stdin);
    cout << "Fill the vector: ";
    while (cin >> val)
    {
        v1.push_back(val);
    }
}

bool is_prefix(const vector<int> &v1, const vector<int> &v2)
{
    // determine the size of smaller vector and use it in the loop
    size_t sz = smaller_size(v1, v2);
    for (size_t i = 0; i != sz; ++i)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

// wanted to use '? :' operator for practice purposes
size_t smaller_size(const vector<int> &v1, const vector<int> &v2)
{
    size_t sv1 = v1.size(), sv2 = v2.size();
    return (sv1 == sv2) ? sv1 : (sv1 > sv2) ? sv2 : sv1;
}