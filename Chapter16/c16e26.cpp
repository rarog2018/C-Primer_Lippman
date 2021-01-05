#include <iostream>
#include <vector>
using namespace std;

class NoDefault
{
public:
    NoDefault(int a) : x(a) {}

    void hello()
    {
        cout << "Hello" << endl;
    }

private:
    int x;
};

// No, it doesn't work because the NoDefault object is not default-constructible
// we would have to provide an argument for the constructor, but even when we do
template class vector<NoDefault>;

// error: 'NoDefault' is not an aggregate, does not have a trivial default constructor,
// and has no 'constexpr' constructor that is not a copy or move constructor
// template class vector<NoDefault(5)>;

int main(void)
{
    // vector<NoDefault> vnd(5);
    return 0;
}