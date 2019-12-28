#include <iostream>
#include <vector>

using namespace std;
int take_int(int a, int b);
int main(void)
{
    // vector which element are a pointers to a function that has two int
    // parameters and returns int
    vector<int (*)(int, int)> fvec;

    // push_back a pointer to our function
    fvec.push_back(take_int);
    cout << "vector size: " << fvec.size() << endl;

    int result = fvec[0](16, 19);
    cout << "The result is: " << result << endl;
    ;
    return 0;
}
int take_int(int a, int b)
{
    cout << "function take_int() called successfuly" << endl;
    cout << a << " " << b << endl;
    return a + b;
}