#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

void print_vec_pair(vector<pair<string, int>> &v)
{
    for (const auto &pair : v)
    {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
}
int main(void)
{
    vector<pair<string, int>> sipvec;
    vector<pair<string, int>> sipvec2;
    vector<pair<string, int>> sipvec3;
    string word;
    int val;
    while (cin >> word >> val)
    {
        // all of them are pretty easily understandable to me, make_pair() is
        // straight forward, but after getting familliar with the syntax
        // i am going to use list initialize the pairs in such scenarios, because
        // its not harder to read and is shorter

        // list initialized pair
        sipvec.push_back({word, val});

        // explicitly constructed pair from word and val variables
        sipvec2.push_back(pair<string, int>(word, val));

        // pair generated by make_pair
        sipvec3.push_back(make_pair(word, val));
    }

    cout << "Vektor 1: ";
    print_vec_pair(sipvec);
    cout << "\nVektor 2: ";
    print_vec_pair(sipvec2);
    cout << "\nVektor 3: ";
    print_vec_pair(sipvec3);
    cout << endl;
    return 0;
}