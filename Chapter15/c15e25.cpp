#include <iostream>
using namespace std;

// If we didn't define the default constructor in the Disc_quote class it would
// become a deleted function in the Bulk_quote class, so we couldn't initialize
// an 'empty' object of Bulk_quote type

// Bulk_quote obj;  // would be an error if there was no default constructor in
// Disc_quote

int main(void)
{

    return 0;
}