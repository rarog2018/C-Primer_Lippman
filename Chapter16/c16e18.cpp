#include <iostream>
using namespace std;

// a)
// it is illegal because it is required that each template parameter has to be
// preceded by a keyword 'typename'
// function doesn't return anything and it takes 3 parameters of same types as
// the template parameters
// template <typename T, U, typename V>
template <typename T, typename U, typename V> // corrected
void f1(T, U, V);

// b)
// illegal, function template has one parameter T which is also the type of the
// returned value by the function, the function parameter list tries to use the
// type T as a variable of type int, which cannot work
template <typename T>
// T f2(int &T);
T f2(T &); // corrected

// c)
// illegal because the 'inline' keyword has to be placed after the template
// parameter list
// there is 1 template parameter, and the function returns T and takes 2 parameters
// one of which is of type T
// inline template <typename T>
template <typename T>
inline T foo(T, unsigned int *); // corrected

// d)
// illegal because there is no return type supplied
template <typename T>
// f4(T, T);
T f4(T, T); // corrected

// e)
// legal, but probably not what author intended to do, the template parameter
// hides the typedef, so Ctype might not be char, but whatever the user provides
typedef char Ctype;
template <typename Ctype>
Ctype f5(Ctype a);

int main(void)
{

    return 0;
}