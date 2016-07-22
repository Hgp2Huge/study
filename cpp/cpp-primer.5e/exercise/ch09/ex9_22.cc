#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> iv{1, 2, 1, 2, 2, 1, 1, 1, 1, 1};
    int some_val = 1;
    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + iv.size() / 2;
    while (iter != mid) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            ++iter;
            mid = iv.begin() + iv.size() / 2;  // after insert element, mid would be changed
        }
        ++iter;
    }

    for (const auto &i : iv)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
