#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    map<string, size_t> word_count;
    string word;

    // this is equivalent to ++word_count[word];
    while (cin >> word)
        ++word_count.insert({word, 0}).first->second;

    /*
    word_count is a map with key of type string and value of type size_t
    word_count.insert   uses the insert method on the map

    word_count.insert({word, 0})    uses the insert method on the map trying to
    insert the value 0 to the key represented by 'word' in the map (if the word
    is not already in the map)

    word_count.insert({word, 0}).first  is the 'first' member of the pair returned
    from the insert method, it is represented by a map word_count

    word_count.insert({word, 0}).first->second is the value of the map word_count
    which has the type size_type

    ++word_count.insert({word, 0}).first->second increment the value of the 
    map_word count, if the key is not in the map add it with value 0 and increment it
    */
    return 0;
}