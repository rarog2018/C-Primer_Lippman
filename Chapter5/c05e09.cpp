#include <iostream>

using namespace std;
int main(void)
{
    unsigned aCnt, eCnt, iCnt, oCnt, uCnt;
    // right associativity
    aCnt = eCnt = iCnt = oCnt = uCnt = 0;
    char ch;
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;
        case 'i':
            ++iCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        case 'u':
            ++uCnt;
            break;
        default:
            break;
        }
    }
    cout << "Number of vowels:\n"
         << "a: " << aCnt << "\ne: " << eCnt
         << "\ni: " << iCnt << "\no: " << oCnt << "\nu: " << uCnt << endl;
}