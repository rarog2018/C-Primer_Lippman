#include <iostream>
#include "Sales_item.h"

using namespace std;
int main(void)
{
    Sales_item book1, book2;
    cout << "Enter Sales_item objects: ";
    cin >> book1 >> book2;
    cout << "\nSum of Book1 and Book2 is " << book1 + book2 << endl;
    return 0;
}