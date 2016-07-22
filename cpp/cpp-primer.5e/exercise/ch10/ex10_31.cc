/*
 *Exercise 10.31:
 *Update the program from the previous exercise so that it prints only the unique elements.
 *Your program should use unqiue_copy (§ 10.4.1, p. 403).
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::unique_copy;

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
    unique_copy(ivec.begin(), ivec.end(), out_iter);
    cout << endl;

    return 0;
}

