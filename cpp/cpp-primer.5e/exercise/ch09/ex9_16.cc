#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l1{1, 2, 3, 4, 5, 6};
    std::list<int> l2{1, 2, 3, 5, 4};
    std::list<int> l3{1, 2, 3, 4, 5};

    std::cout << (l1 == std::list<int>(v.cbegin(), v.cend()) ? "True" : "False") << std::endl;
    std::cout << (l2 == std::list<int>(v.cbegin(), v.cend()) ? "True" : "False") << std::endl;
    std::cout << (l3 == std::list<int>(v.cbegin(), v.cend()) ? "True" : "False") << std::endl;

    return 0;
}
