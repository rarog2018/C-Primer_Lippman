#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<string>::iterator iter;
    vector<string> s1{"Happy birthday",  "Twinkle twinkle"};
    iter = s1.begin();

    // It increments the iterator and yields the copy of the
    // original value. We can print it, but if there are no
    // elements after current element then it will lead to an
    // error.
    // cout << *iter++;

    // It is an error, string does not have ++ operator
    //cout << (*iter)++;

    // It is illegal, because iter is an iterator and does not
    // have a member named empty (dot has higher precedence than *)
    // cout << *iter.empty();

    // It is legal, we can check if the string to which iter
    // points is empty or not.
    // cout << iter->empty();

    // Error: no match for operator++. As in the second example
    // we are trying to increment the value of a string, but
    // strings do not have ++ operators
    // cout << ++*iter;

    // It is legal if the vector has elements, then it checks
    // if the next element is empty. If vector has no elements
    // the program will hang.
    // cout << iter++->empty();
}
