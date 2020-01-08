#include <iostream>
#include <vector>

using namespace std;
char next_text();
unsigned some_value();
int get_value();
unsigned get_bufCnt();
int main(void)
{
    /////////////        a       /////////////
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch)
    {
    case 'a':
        aCnt++;
        break; // added break
    case 'e':
        eCnt++;
        break; // added break
    default:
        iouCnt++;
        break; // added break
    }
    cout << "aCnt: " << aCnt << " eCnt: " << eCnt << " iouCnt: " << iouCnt
         << endl;

    /////////////       b       /////////////
    vector<unsigned> ivec(20, 0);
    unsigned index = some_value();
    int ix; // have to be declared before
    switch (index)
    {
    case 1:
        //int ix = get_value(); // removed initialization
        ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
        break; // addded break
    }
    for (const auto &e : ivec)
        cout << e << " ";
    cout << endl;

    /////////////       c       /////////////
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_value() % 10;
    switch (digit)
    {
        // case 1, 3, 5, 7, 9: // fixed case label
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        oddCnt++; // fixed a typo
        break;
    // case 2, 4, 6, 8, 10: // fixed case label
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
        evenCnt++; // fixed a typo
        break;
    }
    cout << "oddCnt: " << oddCnt << " evenCnt: " << evenCnt << endl;

    /////////////       d       /////////////
    // unsigned ival = 512, jval = 1024, kval = 4096; // these are not integral
    // constant expressions
    constexpr unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt)
    {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
    }
    cout << "bufsize: " << bufsize << endl;
}

char next_text()
{
    char c = 'i';
    return c;
}

unsigned some_value()
{
    return 1;
}

int get_value()
{
    return 9;
}

unsigned get_bufCnt()
{
    return 512;
}