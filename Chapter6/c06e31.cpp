#include <iostream>

using namespace std;
// it is worth to return a reference if we do not want to copy a possibly
// large object (ofc we have to work on an existing non-local object)
// if we want to change such an object we can return a plain reference and
// assign new value to it like we do in the call to get_char
char &get_char(string &str, string::size_type i)
{
    return str[i];
}

// if we do not want to change the object then we should return a reference
// to const like we do in the function below
const string::size_type &get_index(string::size_type &i, string::size_type &j)
{
    return (i >= j) ? i : j;
}
int main(void)
{
    string::size_type i = 2, j = 3;
    string word = "hello";
    cout << "before get_char: " << word << endl;
    // assign 'z' to whatever get_char returns, notice that we can use get_index
    // as an argument, because it returns a value
    // we can do this assignment because reference returns are lvalues
    get_char(word, get_index(i, j)) = 'z';
    cout << "after get_char: " << word << endl;

    return 0;
}