#include <iostream>
#include <string>
#include <list>

using std::list;
using std::string;

int main()
{
    string str;
    list<string> list_strs;
    while (std::cin >> str)
        list_strs.push_back(str);

    for (list<string>::iterator iter = list_strs.begin();
            iter != list_strs.end();
            ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}

// type of iterator ,from deque<string>::iterator to list<string>::iterator
