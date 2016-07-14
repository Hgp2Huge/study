/*
 *Exercise 10.9:
 *Implement your own version of elimDups.
 *Test your program by printing the vector after you read the input,
 *after the call to unique, and after the call to erase.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string;

void printVec(vector<string> &words)
{
    for (const auto &s : words)
        std::cout << s << " ";
    std::cout << std::endl;
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

     return 0;
}
