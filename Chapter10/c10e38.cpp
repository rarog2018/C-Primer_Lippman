#include <iostream>
using namespace std;

int main(void)
{
    /*
    1. Input iterators (read elements in a sequence) supported operations:
        a) == and != operators to compare two iterators,
        b) prefix and postfix ++ operator to advance the iterator,
        c) * operator to read an element (on the right-hand side of an assignment)
        d) -> operator as synonym for (*it).member, to dereference the iterator
        and fetch a member from the underlying object,
        e) can pass through the sequence only once,
    
    2. Output iterators (write elements in a sequence) supported operations:
        b) prefix and postfix ++ operator to advance the iterator,
        b) * operator to read an element (on the left-hand side of an assignment)
        c) can pass through the sequence only once,

    3. Forward iterators (read and write a given sequence) supported operations:
        a) all the operations that Input and Output operators support,
        b) can pass through the sequence multiple times, 

    4. Bidirectional iterators (read and write a given sequence forward and
    backward) supported operations:
        a) all the operations that Forward iterators support,
        b) prefix and postfix -- operator,

    5. Random-access iterators (provide constant-time access to any element
    in a given sequence) supported operations:
        a) all the operations that Bidirectional iterators support,
        b) < <= > >= operators to compare the relative positions of two iterators
        c) + += - -= on an iterator and an integer value, the result is the
        iterator advanced (or retreated) the integer value number of elements
        within the sequence
        d) - operator when applied to two iterators yields the distance 
        between them
        e) [] operator as synonym for *(iter + n)
    */
    return 0;
}