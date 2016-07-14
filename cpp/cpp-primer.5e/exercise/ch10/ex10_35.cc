/*
 *Exercise 10.35:
 *Now print the elements in reverse order using ordinary iterators.
 */

#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
    vector<int>::const_iterator iter;
    for (iter = ivec.cend() - 1; iter != ivec.cbegin(); --iter)
        cout << *iter << " ";
    cout << *iter << endl;
    return 0;
}
