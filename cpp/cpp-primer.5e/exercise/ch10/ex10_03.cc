/*
 *Exercise 10.3:
 *Use accumulate to sum the elements in a vector<int>.
 */

#include <iostream>
#include <vector>
#include <numeric>

using std::vector;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    std::cout << accumulate(nums.cbegin(), nums.cend(), 0) << std::endl;

    return 0;
}
