#include <iostream>
#include <vector>

using std::vector;
int main()
{
    vector<int> vi = {1, 2 ,3 ,4};
    auto iter = vi.begin();
    // a endless loop
    while (iter != vi.end())
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            // print vi
            for (const auto i : vi)
                std::cout << i << " ";
            std::cout << std::endl;
        }
        ++iter; // loop never execute this statement

    return 0;
}

