#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char cs1[] = "Endl";
    const char cs2[] = "Hello World!";
    // the size of the array should be the length of both strings
    // + 2; 1 for NULL character and 1 for space between strings
    char cs3[strlen(cs1) + strlen(cs2) + 2];
    strcpy(cs3, cs2);
    strcat(cs3, " ");
    strcat(cs3, cs1);
    // prints cs3 and its length
    cout << cs3 << endl;
    cout << "CS3 length: " << strlen(cs3) << endl;
    // for educational purposes
    for(auto e : cs3)
        cout << "'" << e << "'";
    return 0;
}
