/*
 *Exercise 3.1
 *Write a program to read a text file. Store each word in a map. The key value of the map is the
 *count of the number of times the word appears in the text. Define a word exclusion set containing
 *words such as a, an, or, the, and, and but. Before entering a word in the map, make sure it is not
 *present in the word exclusion set. Display the list of words and their associated count when the
 *reading of the text is complete. As an extension, before displaying the text, allow the user to query
 *the text for the presence of a word.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int QueryWord(std::map<std::string, int>& words, std::string word)
{
    std::map<std::string, int>::const_iterator it;
    it = words.find(word);
    if (it != words.cend())
        return it->second;
    else
        return 0;
}

int main()
{
    map<string, int> words;
    set<string> word_exclusion = {"a", "an", "or", "the", "and", "but"};

    ifstream in_file("data/words.txt");
    istream_iterator<string> is(in_file), eof;

    string word;
    while (is != eof) {
        word = *is;
        if (!word_exclusion.count(word))
            words[word]++;
        is++;
    }

    string word_to_query = "text";
    cout << "word \"" << word_to_query << "\" appear "
        << QueryWord(words, word_to_query) << " time(s)." << endl;

    for (const auto &w : words)
         cout << "key: " << w.first << "\t value: " << w.second << "\n";

    return 0;
}
