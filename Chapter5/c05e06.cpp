#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    unsigned grade;
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    cout << "Enter your numeric score: ";
    cin >> grade;
    lettergrade = (grade > 50) ? "Grade is not in range" : (grade < 30) ? scores[0] : scores[(grade - 25) / 5];

    cout << "Your grade is: " << lettergrade << endl;
}