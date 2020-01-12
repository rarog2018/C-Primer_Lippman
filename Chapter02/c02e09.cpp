#include <iostream>
using namespace std;

int main(void)
{
    /////////////////////           a           //////////////////////////////
    // it is illegal, because the variable has to be defined before using cin
    // std::cin >> int input_value;
    int input_value;    // first define int value
    cin >> input_value; // then in separate statement use cin

    /////////////////////           b           //////////////////////////////
    // it is illegal, because it tries to assign floating point value to an int
    // variable which will lead to conversion that will truncate aka lead to
    // loss of information which is illegal when initializing using list initia-
    // lization
    // int i = {3.14};
    // int i = (3.14); // or int i = 3.14, the value will be 3

    /////////////////////           c           //////////////////////////////
    // it is illegal, because variable wage was not declared in this scope
    // double salary = wage = 9999.99;
    double wage = 9999.99; // initialize wage
    double salary = wage;  // initialize salary

    /////////////////////           d           //////////////////////////////
    // it is legal, although the value will be truncated to 3
    int i = 3.14;
    return 0;
}