#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::vector; using std::string;
using std::list;

int main()
{
    list<const char*> list_pchar{"Henry", "Peter", "John"};

    vector<string> vec_str;
    vec_str.assign(list_pchar.cbegin(), list_pchar.cend());

    for (const auto &s : vec_str)
        std::cout << s << " ";
    std::cout << std::endl;
}
