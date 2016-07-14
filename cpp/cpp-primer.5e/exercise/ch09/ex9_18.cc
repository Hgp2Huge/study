#include <iostream>
#include <deque>
#include <string>

using std::deque;
using std::string;

int main()
{
    string str;
    deque<string> deq_strs;
    while (std::cin >> str)
        deq_strs.push_back(str);

    for (deque<string>::iterator iter = deq_strs.begin();
            iter != deq_strs.end();
            ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}
