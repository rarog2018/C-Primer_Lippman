#include <iostream>

using namespace std;
int main(void)
{
    unsigned aCnt, eCnt, iCnt, oCnt, uCnt, bsCnt, tabCnt, nwlCnt;
    // right associativity
    aCnt = eCnt = iCnt = oCnt = uCnt = bsCnt = tabCnt = nwlCnt = 0;
    char ch;
    while (cin.get(ch))
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
        case ' ':
            ++bsCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++nwlCnt;
            break;
        default:
            break;
        }
    }
    std::cout << "Number of vowels:\n"
         << "a: " << aCnt << "\ne: " << eCnt
         << "\ni: " << iCnt << "\no: " << oCnt << "\nu: " << uCnt
         << "\nNumber of white characters:\n"
         << "blank spaces: " << bsCnt << "\ntabs: " << tabCnt
         << "\nnew lines: " << nwlCnt << endl;
}