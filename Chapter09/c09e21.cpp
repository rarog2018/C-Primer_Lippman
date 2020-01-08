#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void)
{
    string word;
    vector<string> svec;
    auto iter = svec.begin();
    while (cin >> word)
    {
        // it is legal to do, but vector will be resized and reallocated
        // pretty much each time insert is called, because each element has to
        // be shifted right to maintain the order
        // in a small program like this it might not be a problem, but with
        // bigger input it can become really slow
        iter = svec.insert(iter, word);
        // with list there is no such concern, because list does not move the
        // elements
    }

    for (const auto &elem : svec)
        cout << elem << " ";
    cout << endl;
    return 0;
}
