/*
 *Exercise 10.42:
 *Reimplement the program that eliminated duplicate words that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
 */

#include <iostream>
using std::cout; using std::endl;
#include <list>
using std::list;
#include <string>
using std::string;



void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}


int main()
{
     list<string> slist;
     string s;
     while (std::cin >> s)
         slist.push_back(s);

     elimDups(slist);
     for (auto s : slist)
         cout << s << " ";
     cout << endl;

     return 0;
}
