/*
 *Exercise 10.25:
 *In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition.
 *Rewrite that function to use check_size and bind.
 */


#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::stable_sort; using std::partition; using std::for_each;

#include <functional>
using std::bind; using std::placeholders::_1;

#include <iostream>
using std::cin; using std::cout; using std::endl;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

bool check_size(const string &str, string::size_type sz)
{
    return str.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
            [](const string &str1, const string &str2)
              { return str1.size() < str2.size(); });
    auto check_string_size = bind(check_size, _1, sz);
    auto big_end = partition(words.begin(), words.end(), check_string_size);
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
