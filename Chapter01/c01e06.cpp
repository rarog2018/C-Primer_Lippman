#include <iostream>
int main(void)
{
    int v1 = 0, v2 = 2;
    // it is not legal
    std::cout << "The sum of " << v1;  // this line is legal
    << " and " << v2;                  // there is no expression on the left side of the '<<'
    << " is " << v1 + v2 << std::endl; // operator in both these lines

    // to correct this we can either write it as one statement or as three
    // separate statements each starting with 'std::cout', for example:
    /* std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;*/
    return 0;
}