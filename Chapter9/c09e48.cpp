#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string numbers("0123456789"), name("r2d2");
    // it returns a position on which 'name' occurs, which in this case will
    // be npos, because 'name' does not occur in 'numbers'
    // npos is a const string::size_type initialized with value -1, because
    // size_type is an unsigned type the value underflows to the max value of
    // unsigned int which is 2 to the power of 64 = 18446744073709551615
    const string::size_type result = numbers.find(name);
    cout << result << endl;
    return 0;
}