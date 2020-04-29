#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int n = 5, curr = 0;
    char c;
    char *chDArr = new char[n];
    char *temp;

    // do not skip whitespaces
    while (cin >> noskipws >> c)
    {
        // if the curr has lower value than n, append c to chDArr
        if (curr < n)
        {
            *(chDArr + curr) = c;
            ++curr;
        }
        // if the curr reached n then we need a new dynamic array
        // it works simillar to how vector grows
        else
        {
            // create a new temp dynamic array
            temp = new char[n];
            // copy chDArr to temp
            strcpy(temp, chDArr);
            n *= 2; // double the n size

            // delete the array to which chDArr points
            delete[] chDArr;
            // create a new dynamic array with new, doubled size
            chDArr = new char[n];
            // copy temp to chDArr
            strcpy(chDArr, temp);
            // append the last character
            *(chDArr + curr) = c;
            ++curr;
            // delete the temp array
            delete[] temp;
        }
    }
    // add null in place of the last whitespace
    chDArr[curr - 1] = '\0';
    // print the string
    cout << chDArr << endl;

    delete[] chDArr;
    return 0;
}