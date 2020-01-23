#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    // setup
    // three elements; authors maps last name to first
    multimap<string, string> authors;
    // adds the first element with the key Barth, John
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    // ok: adds the other elements
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    authors.insert({"Alain de Botton", "Lost in the Funhouse"});
    authors.insert({"Alain de Botton", "Revenge"});
    authors.insert({"Alain de Botton", "Jedi the"});

    string search_item("Alain de Botton"); // author we'll look for

    /////////////////////////       ANSWER      //////////////////////////////
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
    {
        // pos is a pair of iterators
        // pos.first is the first iterator (the lower_bound equivalent)
        // pos.first->second dereferences the iterator which is an iterator
        // to a pair<string, string> and fetches the second member of that
        // pair
        cout << pos.first->second << endl;

        // basically pos.first->second is the mapped_type of the multimap
        multimap<string, string>::mapped_type mt = pos.first->second;
        cout << mt << endl;
    }

    return 0;
}