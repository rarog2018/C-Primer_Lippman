#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // all below can be done in many ways, f.e. using strcpy(), but i wanted
    // to use ptrdiff_t, because i cannot recall using it before
    char lit1[] = "Hello ";
    char lit2[] = "World";

    // this includes the \0 after each string literal
    ptrdiff_t sLit1 = end(lit1) - begin(lit1), sLit2 = end(lit2) - begin(lit2);
    ptrdiff_t slLen = sLit1 + sLit2 - 2;

    // dynamically allocated array with appropriate size
    char *pa = new char[slLen - 1];

    ptrdiff_t curr = 0; // will remember where we ended
    // loop through every element in the lit1 literal and assign its value to the
    // appropriate index of the dynamic array
    for (ptrdiff_t nlit1 = 0; nlit1 != sLit1 - 1; ++nlit1, ++curr)
    {
        *(pa + curr) = lit1[nlit1];
    }

    // same for lit2
    for (ptrdiff_t nlit2 = 0; nlit2 != sLit2; ++nlit2, ++curr)
    {
        *(pa + curr) = lit2[nlit2];
    }

    // print the result
    for (ptrdiff_t i = 0; i != slLen; ++i)
    {
        cout << *(pa + i);
    }
    cout << endl;
    delete[] pa;

    // concatenate strings
    string s1 = lit1, s2 = lit2;
    string conc = s1 + s2;
    cout << conc << endl;
    return 0;
}