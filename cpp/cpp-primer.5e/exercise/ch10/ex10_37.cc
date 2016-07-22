/*
 *Exercise 10.37:
 *Given a vector that has ten elements, copy the elements from positions 3 through 7 in reverse order to a list.
 */

#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iterator>
using std::back_inserter;

int main()
{
    vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
    // 0 1 2 3 4 5 6 7 8 9
    //       ^       ^ not include 7
    list<int> ilst;
    copy(ivec.crbegin() + 3, ivec.crbegin() + 7, back_inserter(ilst));
    for (auto i : ilst) cout << i << " ";
    cout << endl;
    return 0;
}
