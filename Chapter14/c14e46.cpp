#include <iostream>
using namespace std;

// I think that defining Sales_data conversions as we done it in the previous
// exercise is not a good idea. The double conversion makes no sense, because
// it is ambiguous what it means - i defined it as the equivalent of the revenue
// but it could also be an average price or some other calculation.
// The string conversion seemd to have more sense, but Sales_data defines an
// << operator and we can process data from the ostream in other ways.

// The only conversion that makes sense would be defining the bool conversion,
// that would check whether the Sales_data object has members filled with data.
// Such conversion operator should be defined as explicit, because it is used
// implicitly only when evaluating the conditions

int main(void)
{
    return 0;
}