#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // maybe in previous standars C++ 11 this was correct but now it generates
    // error: invalid conversion from 'int*' to 'int'
    // ip is an uninitialized pointer to int
    // maybe there should be *&r to indicate that r is a reference to a pointer
    // int *ip, &r = ip;
    // int *ip, *&r = ip;

    /////////////////////           b           //////////////////////////////
    // i is int, ip is a pointer to int, it is a null pointer
    int i, *ip = 0;
    if (!ip)
    {
        cout << "ip is a nullptr" << endl;
    }

    /////////////////////           c           //////////////////////////////
    // ip is a pointer to int, ip2 is an int
    // int *ip, ip2;

    return 0;
}