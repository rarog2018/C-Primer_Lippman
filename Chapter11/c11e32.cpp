#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
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

    for (auto it = authors.begin(); it != authors.end();)
    {
        // get the pair of iterators denoting the range of key occurences
        auto eqr = authors.equal_range(it->first);

        set<string> books;
        // a bit complicated because we cannot initialize books set from the pair
        // of iterators returned from equal_range because they are iterators
        // to pair, not to string
        for (; eqr.first != eqr.second; ++eqr.first)
        {
            // insert to a set the elements in given range (they will be sorted)
            books.insert(eqr.first->second);
        }
        for (const auto &book : books)
        {
            cout << it->first << ": " << book << endl;
            ++it; // increment iterator after every printed book
        }
    }

    return 0;
}