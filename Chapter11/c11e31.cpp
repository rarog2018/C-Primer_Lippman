#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    // setup the multimap
    multimap<string, string> authors{{"Rowling", "HP and the Philosopher's Stone"},
                                     {"Tolkien", "The Return of the King"},
                                     {"Rowling", "HP and the Half-Blood Prince"},
                                     {"Tolkien", "Silmarillion"},
                                     {"Tolkien", "Two Towers"},
                                     {"Sapkowski", "The Last Wish"}};

    for (const auto &elem : authors)
    {
        cout << elem.first << ": " << elem.second << endl;
    }

    vector<string> toDelete{"Rowling", "Martin"};
    cout << "\nAuthors to delete: " << toDelete[0] << ", " << toDelete[1] << endl;
    for (auto &author : toDelete)
    {
        auto it = authors.find(author);
        // check if the author is in the list and print adequate message
        if (it == authors.end())
        {
            cout << "The author " << author << " is not on the list." << endl;
        }
        else
        {
            // get the number of author's entries
            auto cnt = authors.count(author);
            // erase all of the entries (classic loop)
            for (; cnt != 0; ++it, --cnt)
            {
                cout << "Erasing entry: " << it->first << ": " << it->second << endl;
                authors.erase(it);
            }
        }
    }

    cout << "\nAfter erasing: " << endl;
    for (const auto &elem : authors)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    return 0;
}