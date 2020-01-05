#include <iostream>
#include "Sales_item.h"

using namespace std;
int main(void)
{
    Sales_item book, sum;
    cout << "Enter Sales_item objects: ";
    if (cin >> sum)
    {
        while (cin >> book)
        {
            sum += book;
        }
    }
    cout << "\nSum of the transactions is " << sum << endl;
    return 0;
}