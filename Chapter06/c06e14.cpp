#include <iostream>
#include <vector>

using namespace std;

// when we want to change the original object's value we should pass it as a
// reference, also when the object is huge (like vector in this example), it
// is a good idea to not make another large copy, but use original object
// instead
void change_object(int &a)
{
    a = 17;
}
void print_el_vector(const vector<int> &v)
{
    cout << "173599th element of this vector is = " << v[173599] << endl;
}

// when we do not want to change original object's value, and the fancy stuff
// that we do inside of the function puts us in risk of messing the original
// object, we should not use reference, especially if object is small, the
// safety provided by a copy might outweigh the cost of the additional memory
void f(int a)
{
    // fancy stuff
}

int main(void)
{
    int x = 12;
    vector<int> horrendouslyBigVector(9999999, 15);
    print_el_vector(horrendouslyBigVector);
    return 0;
}