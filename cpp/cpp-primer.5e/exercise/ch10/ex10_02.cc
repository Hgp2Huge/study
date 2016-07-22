/*
 *Exercise 10.2:
 *Repeat the previous program, but read values into a list of strings.
 */

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::list; using std::string;

int main()
{
    list<string> lstr;
    string s;
    while (std::cin >> s)
        lstr.push_back(s);
    std::cout << count(lstr.begin(), lstr.end(), "me") << std::endl;

    return 0;
}
