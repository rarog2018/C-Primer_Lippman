#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    vector<double> vd{0.7, 2.3, 3.3};
    //vector<int> vi(vd);           This is illegal
    vector<double> vd2(vd);         // This is ok

    // Illegal, types of both container and container
    // elements must match exactly
    //deque<int> di(vd);

    // this is ok, because when iterators get
    // dereferenced the double values of vd
    // elements are converted to int
    deque<int> di2(vd.begin(), vd.end());

    for(const auto &e : di2)
        cout << e << " ";

}
