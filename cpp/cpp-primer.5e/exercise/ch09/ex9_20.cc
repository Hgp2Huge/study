#include <iostream>
#include <list>
#include <deque>

using std::list; using std::deque;

int main()
{
    list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd, even;
    for (const auto &num : l) {
        if (num % 2)
            odd.push_back(num);
        else
            even.push_back(num);
    }

    for (const auto &num : odd)
        std::cout << num << " ";
    std::cout << std::endl;
    for (const auto &num : even)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
