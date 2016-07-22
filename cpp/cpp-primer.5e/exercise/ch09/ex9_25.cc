#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};

    for (const auto &i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    vector<int>::iterator elem1, elem2;
    elem1 = v.begin() + 1;
    //elem2 = elem1;                // test elem1 = elem2
    //elem2 = v.end();              // test elem2 is off-the-end iterator
    elem1 = elem2 = v.end();      // test elem1 and elem2 both are off-the-end iterator
    elem1 = v.erase(elem1, elem2);

    for (const auto &i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    if (elem1 == v.end())
        std::cout << "iterator is off-the-end." << std::endl;
    else
        std::cout << "value of iterator: " << *elem1 << std::endl;

    return 0;
}
