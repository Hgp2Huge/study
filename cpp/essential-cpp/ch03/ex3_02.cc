/*
 *Exercise 3.2
 *Read in a text file — it can be the same one as in Exercise 3.1 — storing it in a vector. Sort the
 *vector by the length of the string. Define a function object to pass to sort(); it should accept two
 *strings and return true if the first string is shorter than the second. Print the sorted vector.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class ShorterThan {
public:
    bool operator()(const std::string &s1, const std::string &s2) {
        return s1.size() < s2.size();
    }
};

int main()
{
    ifstream in_file("data/words.txt");
    if (!in_file) {
        cerr << "Error in open file. " << endl;
        return -1;
    }

    vector<string> text;
    string word;

    while (in_file >> word)
        text.push_back(word);


    sort(text.begin(), text.end(), ShorterThan());

    for (const auto s : text)
        cout << s << " ";
    cout << endl;

    return 0;
}
