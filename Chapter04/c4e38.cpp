#include <iostream>

using namespace std;

int main(void)
{
    int i = 3, j = 2;
    // it does pretty much nothing because it converts the result of (j/i)
    // expression which is an already truncated integer
    double slope = static_cast<double>(j / i);
    cout << slope << endl;

    // this is what author intended to do
    slope = static_cast<double>(j) / static_cast<double>(i);
    cout << slope << endl;
}