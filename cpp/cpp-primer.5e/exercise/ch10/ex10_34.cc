/*
 *Exercise 10.34:
 *Use reverse_iterators to print a vector in reverse order.
 */


#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int>  ivec{0,1,2,3,4,5,6,7,8,9};
    // vector<int>::const_reverse_iterator r_iter;
    for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter)
        std::cout << *r_iter << " ";
    std::cout << std::endl;

    return 0;
}
