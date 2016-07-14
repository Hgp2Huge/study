#include <iostream>
#include <vector>

// Exercise 9.4
bool contains(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right, int value)
{
    for (; left != right; ++left)
        if (*left == value) return true;
    return false;
}


// Exercise 9.5
std::vector<int>::const_iterator find(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right, int value)
{
    for (; left != right; ++left)
        if (*left == value) return left;
    return right;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>::const_iterator begin = vec.begin();
    std::vector<int>::const_iterator end = vec.end();
    // Test 9.4
    if (contains(begin, end, 5))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    if (contains(begin + 3, end - 2, 9))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    // Test 9.5
    std::vector<int>::const_iterator iter;
    iter = ::find(begin, end, 5);
    if (iter != end)
        std::cout << *iter << std::endl;
    else
        std::cout << "Value not found!" << std::endl;
    iter = ::find(begin + 3, end - 2, 9);
    if (iter != end -2)
        std::cout << *iter << std::endl;
    else
        std::cout << "Value not found!" << std::endl;
}
