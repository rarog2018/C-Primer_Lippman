#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void)
{
    vector<string> svec;
    svec.reserve(1024);
    string word = "Hello";
    // while(cin >> word)
    for (size_t i = 0; i != 256; ++i)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);
    // if program reads 256 words, after resize the size will be:
    // 256 + 128 = 384, capacity 1024
    cout << svec.size() << " " << svec.capacity() << endl;

    svec.resize(256);
    for (size_t i = 0; i != 256; ++i)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);
    // if program reads 512 words, after resize the size will be:
    // 512 + 256 = 768, capacity 1024
    cout << svec.size() << " " << svec.capacity() << endl;

    svec.resize(512);
    for (size_t i = 0; i != 488; ++i)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);
    // if program reads 1000 words, after resize the size will be:
    // 1000 + 500 = 1500, capacity 2000 (at least 1500)
    cout << svec.size() << " " << svec.capacity() << endl;

    svec.resize(0);
    svec.reserve(1024);
    for (size_t i = 0; i != 1048; ++i)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);
    // if program reads 1048 words, after resize the size will be:
    // 1048 + 524 = 1572, capacity 2000 (at least 1572)
    cout << svec.size() << " " << svec.capacity() << endl;
    return 0;
}