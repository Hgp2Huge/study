#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string;

int main()
{
    vector<string> vstr;
    string word;
    auto iter = vstr.begin();
    while (std::cin >> word)
        iter = vstr.insert(iter, word);

    for (const auto &w : vstr)
        std::cout << w << " ";
    std::cout << std::endl;
    return 0;
}


// 插入时，先移动已有的元素.
// 插入后返回当前插入的元素的位置
