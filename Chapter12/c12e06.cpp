#include <iostream>
#include <vector>
using namespace std;

// returns vector
vector<int> *ret_i_vec(vector<int>::size_type i);
// writes to a vector
istream &fill_vec(istream &is, vector<int> &v);
// prints a vector
ostream &print_vec(ostream &os, vector<int> &v);

int main(void)
{
    auto pivec = ret_i_vec(5);
    cout << pivec->size() << endl;

    fill_vec(cin, *pivec);
    print_vec(cout, *pivec) << endl;

    delete pivec;
    return 0;
}

vector<int> *ret_i_vec(vector<int>::size_type i)
{
    return new vector<int>(i);
}

istream &fill_vec(istream &is, vector<int> &v)
{
    for (auto &e : v)
    {
        is >> e;
    }
    return is;
}

ostream &print_vec(ostream &os, vector<int> &v)
{
    for (auto &e : v)
    {
        os << e << " ";
    }
    return os;
}