/*
 *Exercise 10.1:
 *The algorithm header defines a function named count that, like find, takes a pair of iterators and a value.
 *count returns a count of how often that value appears.
 *Read a sequence of ints into a vector and print the count of how many elements have a given value.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    int tmp;
    vector<int> nums;
    while (std::cin >> tmp)
        nums.push_back(tmp);
    std::cout << count(nums.begin(), nums.end(), 5) << std::endl;

    return 0;
}
