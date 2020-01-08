#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> cin_to_vector();
void print_adj_sum(vector<int> v);
void print_symetrical_sum(vector<int> v);

int main()
{
    vector<int> v1{cin_to_vector()};
    print_adj_sum(v1);
    print_symetrical_sum(v1);
    return 0;
}

 vector<int> cin_to_vector()
 {
     vector<int> x;
     int i;
     while(cin >> i)
        x.push_back(i);
    return x;
 }

 void print_adj_sum(vector<int> v)
 {
     //we go to end - 1 element
     for(auto it = v.cbegin(); it != v.cend() - 1; it++)
     {
         cout << (*it) + (*(it + 1)) << " ";
     }
     cout << endl;
 }

 void print_symetrical_sum(vector<int> v)
 {
    auto start = v.cbegin(), finish = v.cend() - 1;
     for(auto mid = start + (finish - start) / 2; start != mid + 1; start++, finish--)
     {
         if(start == finish)
            cout << (*start);
         else
            cout << (*start) + (*finish) << " ";
     }
 }
