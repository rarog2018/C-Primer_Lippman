#include <iostream>
#include "Sales_item.h"

using namespace std;
int main(void)
{
    Sales_item book1, book2;
    cout << "Enter Sales_item objects: ";
    cin >> book1 >> book2;
    cout << "\nBook1: " << book1 << endl;
    cout << "Book2: " << book2 << endl;
    return 0;
}