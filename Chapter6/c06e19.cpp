#include <iostream>
#include <vector>

using namespace std;
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
int main(void)
{
    vector<int> vec(10);
    /////////////////       a       /////////////////
    // this call is illegal because calc() has only one parameter
    // calc(23.4, 55.1);

    /////////////////       b       /////////////////
    // legal, arguments match parameters
    // count("abcda", 'a');

    /////////////////       c       /////////////////
    // legal, 66 will be converted to double
    // calc(66);

    /////////////////       d       /////////////////
    // legal, first two arguments match, and '3.8' will be truncated to 3
    // sum(vec.begin(), vec.end(), 3.8);
    return 0;
}
