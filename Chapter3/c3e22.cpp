#include <iostream>
#include <vector>
#include <string>
using namespace std;
void change_paragraph_toupper(vector<string> &text);
void print_vector(vector<string> text);
int main()
{
    vector<string> text{"This is first paragraph", "IT migt still be first paragraph", "", "The last paragraph"};
    change_paragraph_toupper(text);
    print_vector(text);
    return 0;
}

void change_paragraph_toupper(vector<string> &text)
{
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        {
            for(auto curr = (*it).begin(); curr != (*it).end(); curr++)
                *curr = toupper(*curr);
        }
}

void print_vector(vector<string> text)
{
    for (auto it = text.cbegin(); it != text.cend(); ++it)
        {
            cout << *it << endl;
        }
}
