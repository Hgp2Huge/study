/*
 *Exercise 10.18:
 *Rewrite biggies to use partition instead of find_if.
 *We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>

#include <iostream>
using std::cin; using std::cout; using std::endl;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
            [](const string &str1, const string &str2)
              { return str1.size() < str2.size(); });
    auto big_end = partition(words.begin(), words.end(),
            [sz](const string &str)
              { return str.size() >= sz; });
    auto count = big_end - words.begin();
    cout << count << " " << (count > 1 ? "words" : "word")
        << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), big_end,
            [](const string &str) { cout << str << " "; });
    cout << endl;
}


int main()
{
     vector<string> v_str;
     string str;
     while (cin >> str)
         v_str.push_back(str);

     biggies(v_str, 5);

     return 0;
}
