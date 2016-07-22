/*
 *Exercise 10.6:
 *Using fill_n, write a program to set a sequence of int values to 0.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    fill_n(ivec.begin(), ivec.size(), 0);
    for (const auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
