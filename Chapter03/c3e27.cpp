#include <iostream>

using namespace std;
int txt_size();

int main()
{
    unsigned buf_size = 1024;       // it should be an error, because its not a constant expression
                                    // but for some reason it works
    int ia[buf_size];
    int ib[4 * 7 - 14];             // its correct, the result of the expression is 14
    int ic[txt_size()];             // it should be an error but it works
    // on my computer
    //char st[11] = "fundamental";  // this is an error because the string is too long
    buf_size = 55;                  // even after changing the value, it still works
    ia[90] = 7;
    cout << "Size of ia: " << sizeof(ia) / 4 << endl;       // no error, size is printed
    cout << "Size of ib: " << sizeof(ib) / 4 << endl;
    cout << "Size of ic: " << sizeof(ic) / 4 << endl;
    return 0;
}

int txt_size()
{
    return 17;
}
