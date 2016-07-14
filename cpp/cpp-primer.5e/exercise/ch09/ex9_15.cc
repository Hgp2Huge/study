#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3, 4, 5, 6};
    std::vector<int> v3{1, 2, 3, 5, 4};
    std::vector<int> v4{1, 2, 3, 4, 5};

    std::cout << (v1 == v2 ? "True" : "False") << std::endl;
    std::cout << (v1 == v3 ? "True" : "False") << std::endl;
    std::cout << (v1 == v4 ? "True" : "False") << std::endl;

    return 0;
}
