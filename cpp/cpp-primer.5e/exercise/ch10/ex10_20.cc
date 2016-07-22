/*
 *Exercise 10.20:
 *The library defines an algorithm named count_if.
 *Like find_if, this function takes a pair of iterators denoting an input range and a predicate
 *that it applies to each element in the given range.
 *count_if returns a count of how often the predicate is true.
 *Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.
 */


#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::stable_sort; using std::sort; using std::count_if;
using std::stable_partition; using std::for_each;

#include <iostream>
using std::cin; using std::cout; using std::endl;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz, std::ostream &os, char c)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
            [](const string &str1, const string &str2)
              { return str1.size() < str2.size(); });
    auto big_end = stable_partition(words.begin(), words.end(),
            [sz](const string &str)
              { return str.size() > sz; });
    auto count = count_if(words.cbegin(), words.cend(),
            [=](const string &str) { return str.size() > sz; });
    cout << count << " " << (count > 1 ? "words are" : "word is")
        << " greater than length " << endl;
    for_each(words.begin(), big_end,
            [&os, c](const string &str) { os << str << c; });
    cout << endl;
}


int main()
{
     vector<string> v_str;
     string str;
     while (cin >> str)
         v_str.push_back(str);

     biggies(v_str, 6, cout, ' ');

     return 0;
}
