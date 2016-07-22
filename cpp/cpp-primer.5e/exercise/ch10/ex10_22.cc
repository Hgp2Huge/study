/*
 *Exercise 10.22:
 *Rewrite the program to count words of size 6 or less using functions in place of the lambdas.
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::count_if;

#include <functional>
using std::bind; using std::placeholders::_1;

#include <iostream>
using std::cin; using std::cout; using std::endl;

bool isShorter(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}

int main()
{
    vector<string> vstr;
    string str;
    while (cin >> str)
        vstr.push_back(str);
    auto check6 = bind(isShorter, _1, 6);
    auto count = count_if(vstr.begin(), vstr.end(), check6);
    cout << count << (count > 1 ? " words" : " word")
        << " length is shorter than 6 or equal." << endl;
    return 0;
}
