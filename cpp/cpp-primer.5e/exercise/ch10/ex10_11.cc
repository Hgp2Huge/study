/*
 *Exercise 10.11:
 *Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups.
 *Print the vector to verify that your program is correct.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector; using std::string;

void printVec(vector<string> &words)
{
    for (const auto &s : words)
        std::cout << s << " ";
    std::cout << std::endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    printVec(words);
    sort(words.begin(), words.end());
    printVec(words);
    auto end_unique = unique(words.begin(), words.end());
    printVec(words);
    words.erase(end_unique, words.end());
    printVec(words);
}


int main()
{
     vector<string> svec;
     string s;
     while (std::cin >> s)
         svec.push_back(s);

     elimDups(svec);
    stable_sort(svec.begin(), svec.end(), isShorter);
    printVec(svec);

     return 0;
}
