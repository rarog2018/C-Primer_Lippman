#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void)
{
    // declaration of a vector that stores string elements
    vector<string> svec;
    // allocate memory for 1024 string elements
    svec.reserve(1024);
    // declaration of string type variable
    string word;
    // store user input in string variable untill the input is invalid
    while (cin >> word)
        svec.push_back(word); // push that variable into vector
    // get the number of elements that svec currently holds, add to it half
    // of this number and set the size to the result of this computation
    svec.resize(svec.size() + svec.size() / 2);

    cout << svec.size() << " " << svec.capacity() << endl;
    return 0;
}