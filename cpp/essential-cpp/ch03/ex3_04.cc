/*
 *Exercise 3.4
 *Write a program to read a sequence of integer numbers from standard input using an
 *istream_iterator. Write the odd numbers into one file using an ostream_iterator. Each value should
 *be separated by a space. Write the even numbers into a second file, also using an ostream_iterator.
 *Each of these values should be placed on a separate line.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

class odd_num {
public:
    bool operator()(const int n) { return n%2; }
};

int main()
{
    ofstream odd_out_file("data/odd_nums.txt"),
             even_out_file("data/even_nums.txt");

    istream_iterator<int> is(cin), eof;
    ostream_iterator<int> oss_iter_odd(odd_out_file, " "),
                          oss_iter_even(even_out_file, "\n");

    vector<int> ivec;
    copy(is, eof, back_inserter(ivec));

    vector<int>::iterator separator = partition(ivec.begin(), ivec.end(), odd_num());
    copy(ivec.begin(), separator, oss_iter_odd);
    copy(separator, ivec.end(), oss_iter_even);

    return 0;
}
