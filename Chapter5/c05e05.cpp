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
    if (grade > 50)
    {
        cout << "Grade is not in the range." << endl;
        return 0;
    }
    if (grade >= 30)
    {
        lettergrade = scores[(grade - 25) / 5];
        if (grade != 50)
        {
            if (grade % 5 == 4)
            {
                lettergrade += "+";
            }
            else if (!(grade % 5))
            {
                lettergrade += "-";
            }
        }
    }
    else
    {
        lettergrade = scores[0];
    }

    cout << "Your grade is: " << lettergrade << endl;
}