#include <iostream>
#include <vector>

using namespace std;
int add_int(int a, int b);
int substract_int(int a, int b);
int multiply_int(int a, int b);
int divide_int(int a, int b);
int main(void)
{
    int x = 10, y = 5;
    // vector which element are a pointers to a function that has two int
    // parameters and returns int
    vector<int (*)(int, int)> fvec;

    // vector that stores strings
    vector<string> svec{"add", "substract", "multiply", "divide"};

    // push_back pointers to our functions
    fvec.push_back(add_int);
    fvec.push_back(substract_int);
    fvec.push_back(multiply_int);
    fvec.push_back(divide_int);

    // check if vector has expected size
    cout << "vector size: " << fvec.size() << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // call each element in the vector and print result
    // loop for fun
    for (int i = 0; i != fvec.size(); ++i)
    {
        // a bit cryptic looking
        cout << svec[i] << ": " << fvec[i](x, y) << endl;
    }
    return 0;
}
int add_int(int a, int b)
{
    return a + b;
}
int substract_int(int a, int b)
{
    return a - b;
}
int multiply_int(int a, int b)
{
    return a * b;
}
int divide_int(int a, int b)
{
    return a / b;
}