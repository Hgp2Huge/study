/*
 *Exercise 10.27:
 *In addition to unique (§ 10.2.3, p. 384), the library defines function named unique_copy
 *that takes a third iterator denoting a destination into which to copy the unique elements.
 *Write a program that uses unique_copy to copy the unique elements from a vector into an initially empty list.
 */

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::unique_copy; using std::for_each;
using std::sort;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    list<int> ilst;
    sort(ivec.begin(), ivec.end());
    unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
    for_each(ilst.cbegin(), ilst.cend(), [](int i) { cout << i << " "; });
    cout << endl;

    return 0;
}
