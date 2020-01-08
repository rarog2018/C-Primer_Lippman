#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int grade;
    string finalgrade;
    // first part uses conditional operator
    cout << "Enter grade (0 - 100): ";
    cin >> grade;
    // check condition: if true evaluate left expression
    // if false evaluate right expression, which in our
    // case is also a condition, and so on
    // when done assign the result to the variable
    finalgrade = (grade > 90) ? "high pass"
            : (grade > 75) ? "pass"
            : (grade >= 60) ? "low pass" : "fail";
    cout << finalgrade << endl;

    cout << "Enter grade (0 - 100): ";
    cin >> grade;
    // in this case both ways look pretty readable in my
    // opinion, its just the matter of exposure to the
    // conditional operator, it becomes less and less
    // cryptic looking for me
    if(grade > 90)
        cout << "high pass";
    else if(grade > 75)
        cout << "pass";
    else if(grade >= 60)
        cout << "low pass";
    else
        cout << "fail";
    cout << finalgrade << endl;
}
