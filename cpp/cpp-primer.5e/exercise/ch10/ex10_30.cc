/*
 *Exercise 10.30:
 *Use stream iterators, sort, and copy to read a sequence of integers from the standard input,
 *sort them, and then write them back to the standard output.
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::copy;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    // construct from two iterator
    vector<int> ivec(in_iter, eof);
    sort(ivec.begin(), ivec.end());
    copy(ivec.begin(), ivec.end(), out_iter);
    cout << endl;

    return 0;
}

