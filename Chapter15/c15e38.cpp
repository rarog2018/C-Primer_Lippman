#include <iostream>
using namespace std;

int main(void)
{
    // a) BinaryQuery a = Query("fiery") & Query("bird");
    // Illegal because BinaryQuery is an abstract class, so we canot create an
    // object of its type

    // b) AndQuery b = Query("fiery") & Query("bird");
    // Illegal because we didn't define a conversion from Query to AndQuery

    // c) OrQuery c = Query("fiery") & Query("bird");
    // Illegal, for same resons as in b)
    return 0;
}