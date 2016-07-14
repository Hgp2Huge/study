/*
 *Exercise 10.29:
 *Write a program using stream iterators to read a text file into a vector of strings.
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    vector<string> vstr;
    string s;
    ifstream ifs("data/words.txt");
    istream_iterator<string> in_iter(ifs), end;
    ostream_iterator<string> out_iter(cout, " ");
    while (in_iter != end)
        vstr.push_back(*in_iter++);
    ifs.close();

    copy(vstr.cbegin(), vstr.cend(), out_iter);
    cout << endl;

    return 0;
}
