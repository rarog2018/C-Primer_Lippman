#include <iostream>

using namespace std;
int main(void)
{
    unsigned aCnt, eCnt, iCnt, oCnt, uCnt, bsCnt, tabCnt, nwlCnt, ffCnt,
        flCnt, fiCnt;
    // right associativity
    aCnt = eCnt = iCnt = oCnt = uCnt = bsCnt = tabCnt = nwlCnt = ffCnt = flCnt = fiCnt = 0;
    char ch;
    char last = ' ';
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
        {
            ++iCnt;
            if (ch == 'i' && last == 'f')
                ++fiCnt;
            break;
        }
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
        case 'f':
        {
            if (last == 'f')
                ffCnt++;
            break;
        }
        case 'l':
        {
            if (last == 'f')
                flCnt++;
            break;
        }
        default:
            break;
        }
        last = ch;
    }
    std::cout << "Number of vowels:\n"
              << "a: " << aCnt << "\ne: " << eCnt
              << "\ni: " << iCnt << "\no: " << oCnt << "\nu: " << uCnt
              << "\nNumber of white characters:\n"
              << "blank spaces: " << bsCnt << "\ntabs: " << tabCnt
              << "\nnew lines: " << nwlCnt
              << "\nNumber of sequences:\n"
              << "ff: " << ffCnt << "\nfl: " << flCnt << "\nfi: "
              << fiCnt << endl;
}