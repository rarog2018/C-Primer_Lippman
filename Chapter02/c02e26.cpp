#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // illegal, const variable requires initialization
    // const int buf;

    /////////////////////           b           //////////////////////////////
    // legal
    int cnt = 0;

    /////////////////////           c           //////////////////////////////
    // legal
    const int sz = cnt;

    /////////////////////           d           //////////////////////////////
    // ++cnt is legal, ++sz is legal, because we cannot change the value of
    // a const object
    ++cnt;
    // ++sz;
    
    return 0;
}