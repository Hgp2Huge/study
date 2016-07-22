/*
 *Exercise 10.36:
 *Use find to find the last element in a list of ints with value 0.
 */

#include <iostream>
using std::cout; using std::endl;
#include <list>
using std::list;
#include <algorithm>
using std::find;

int main()
{
    list<int> ilst{0,1,2,0,1,2,0,1,2};
    auto pos = find(ilst.crbegin(), ilst.crend(), 0);
    cout << *pos << endl;
    return 0;
}
