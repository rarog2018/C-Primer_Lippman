#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int ival = -1;
    int *ptr = &ival;
    vector<int> vec{3, 6, 9, 12};
    cout << &ival << " " << ival << endl;
    cout << ptr << " " << *ptr << endl;
    // Left expression checks if ptr is not a null pointer, it is explicitly
    // said that it points to an int, hence we know that it will evaluate to true.
    // Right expression will be true if current value to which pointer points to
    // is not 0, it also increments the pointer -> points it after the element
    // that it points to currently, which in this case is an error, because we
    // point to a single variable, so we have no idea what is after it.
    // It can be corrected in multiple ways depends on what our pointer points to
    // and what we want to achieve.
    if(ptr != 0 && *ptr++)
        cout << "Pointer condition passed. " << ptr << " " << *ptr << endl;
    else
        cout << "Pointer condition did not pass. " << ptr << " " << *ptr << endl;
    ptr = &ival;
    // In this case maybe just check if current value is not 0 and then increment
    // the actual value, although it will still check if the original value is not
    // 0 and we already checked that
    if(ptr != 0 && (*ptr)++)
        cout << "Pointer condition passed. " << ptr << " " << *ptr << endl;
    else
        cout << "Pointer condition did not pass. " << ptr << " " << *ptr << endl;

    // First it copies the original value into temp variable, then it increments
    // the original variable. It checks if the original value is not 0. In our
    // case it is not, so then the right side of the condition is checked.
    // It checks the if the value after incrementation is equal to 0, in our case
    // it is.
    // Nothing incorrect or dangerous happens here.
    ival = -1;
    if(ival++ && ival)
        cout << "Ival condition passed. " << ival << endl;
    else
        cout << "Ival condition did not pass. " << ival << endl;

    ival = 0;
    // <= does not guarantee the order in which the expressions will be evaluated
    if(vec[ival++] <= vec[ival])
    {
        // As we can see the order in which these expressions get evaluated
        // is undefined in single statement.
        cout << "Single statement: vec[ival] = " << vec[ival] << ", vec[ival++] = "
        << vec[ival++] << endl;
        // In separate statements everything works as expected
        cout << "Separate statements: vec[ival] = " << vec[ival];
        cout << ", vec[ival++] = " << vec[ival++] << endl;

    }
    // So if we want to check if the element after vec[ival] is lesser or equal
    // then we should write this expression like this
    if(vec[ival + 1] <= vec[ival])
        cout << "True: vec[ival + 1] is lesser or equal to vec[ival]" << endl;
    else
        cout << "False: vec[ival + 1] is not lesser or equal to vec[ival]" << endl;
}
