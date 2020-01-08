#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    // vector<int> ivec;
    vector<int> ivec{17, 19, 1, 33};
    // this line will raise an exception if vector is empty
    cout << ivec.at(0) << endl;
    // this line will terminate the program with code=3221225477 (in my case)
    cout << ivec[0] << endl;
    // this line will terminate the program with code=3221225477 (in my case)
    cout << ivec.front() << endl;
    // same situation as in 2 previous lines
    cout << *(ivec.begin()) << endl;
    return 0;
}