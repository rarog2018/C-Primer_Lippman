#include <iostream>
using namespace std;

#define MAX 100
// basic Stack template
template <typename T>
class Stack
{
public:
    T a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(T x);
    T pop();
    T peek();
    bool isEmpty();

private:
    int top;
};

// a)
// this is a function declaration, so the compilator won't generate the code
// to instantiate this template we would have to use this function, which we
// don't (at least at this line :>)
void f1(Stack<char>);

class Exercise
{
public:
    // both definitions below insantiate the Stack<double> and Stack<int> classes
    Stack<double> &rsd; // (b)
    Stack<int> si;      // (c)
};

int main(void)
{
    // some tests
    /*
    Stack<double> s;
    s.push(17.33);
    s.push(12.99);
    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    */
    // d) instantiates Stack<char>
    Stack<char> *sc;

    // e) Stack<char> is already instantiated, so it does not intantiate it
    // f1(*sc);

    // f) seems like it also intantiates the Stack<string> class, cause it cannot
    // be used with an incomplete class
    int iObj = sizeof(Stack<string>);
    cout << iObj << endl;
    return 0;
}

void f1(Stack<char> s)
{
    cout << "Yup" << endl;
}
///////////////////////////////////////////////////////////////////////////////
// Stack members definitions
template <typename T>
bool Stack<T>::push(T x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        T x = a[top--];
        return x;
    }
}

template <typename T>
T Stack<T>::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        T x = a[top];
        return x;
    }
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (top < 0);
}