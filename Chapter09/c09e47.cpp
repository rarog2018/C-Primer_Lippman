#include <iostream>
#include <string>

using namespace std;
void find_fo(string source, string searched, string what);
void find_fno(string source, string searched, string what);
int main(void)
{
    string numbers("0123456789"), a("ab2c3d7R4E6");
    string letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // first version using find_first_of
    find_fo(numbers, a, "number");
    find_fo(letters, a, "letter");

    // second version using find_first_not_of
    find_fno(letters, a, "not letter");
    find_fno(numbers, a, "not number");

    return 0;
}

void find_fo(string source, string searched, string what)
{
    string::size_type pos = 0;
    // loop until there is a match and store index of occurency in
    // pos variable
    while ((pos = searched.find_first_of(source, pos)) != string::npos)
    {
        cout << "found " << what << " at index: " << pos
             << " element is " << searched[pos] << endl;
        ++pos; // incerement pos to prevent infinite loop
    }
    cout << endl;
}

void find_fno(string source, string searched, string what)
{
    string::size_type pos = 0;
    // loop until there is a match and store index of occurency in
    // pos variable
    while ((pos = searched.find_first_not_of(source, pos)) != string::npos)
    {
        cout << "found " << what << " at index: " << pos
             << " element is " << searched[pos] << endl;
        ++pos; // incerement pos to prevent infinite loop
    }
    cout << endl;
}