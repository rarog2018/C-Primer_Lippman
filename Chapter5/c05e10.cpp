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
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
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