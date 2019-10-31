#include <iostream>

using namespace std;
void swap_pointers(int *&px, int *&py);
int main(void)
{
    int a = 5, b = 7;
    int *pa = &a, *pb = &b;
    cout << "pa points to: " << *pa << " pb points to: " << *pb << endl;
    cout << "pa address: " << pa << " pb address: " << pb << endl;
    swap_pointers(pa, pb);
    cout << "pa points to: " << *pa << " pb points to: " << *pb << endl;
    cout << "pa address: " << pa << " pb address: " << pb << endl;
    cout << a << " " << b << endl;
    return 0;
}
// px, py are references to pointers
void swap_pointers(int *&px, int *&py)
{
    // temp points to whate
    int *temp = px;
    px = py;
    py = temp;
}