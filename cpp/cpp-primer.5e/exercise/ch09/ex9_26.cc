#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    int len = sizeof(ia) / sizeof(ia[0]);
    vector<int> odd;
    list<int> even;
    for (int i = 0; i < len; ++i) {
        odd.push_back(ia[i]);
        even.push_back(ia[i]);
    }

    for (vector<int>::iterator iter = odd.begin(); iter != odd.end();) {
         if (*iter % 2)
             ++iter;
         else
             iter = odd.erase(iter);
    }
    for (list<int>::iterator iter = even.begin(); iter != even.end();) {
         if (*iter % 2)
             iter = even.erase(iter);
         else
             ++iter;
    }
    std::cout << "vector: ";
    for (const auto &i : odd)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "list: ";
    for (const auto &i : even)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

