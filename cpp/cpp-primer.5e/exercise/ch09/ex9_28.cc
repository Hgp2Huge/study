#include <iostream>
#include <string>
#include <forward_list>

using std::string; using std::forward_list;

void find_insert_str(forward_list<string>& flst, string s1, string s2)
{
    bool elem_found = false;
    auto last = flst.begin();
    for (auto curr = flst.begin(); curr != flst.end(); ++curr) {
        if (*curr == s1) {
            curr = flst.insert_after(curr, s2);
            elem_found = true;
        }
        last = curr;
    }
    if (!elem_found)
        flst.insert_after(last, s2);
}


int main()
{
    forward_list<string> flst_str = {"aaa", "bbb", "ccc", "ddd"};

    find_insert_str(flst_str, "bbb", "ggg");
    for (const auto &str : flst_str)
        std::cout << str << " ";
    std::cout << std::endl;

    find_insert_str(flst_str, "eee", "hhh");
    for (const auto &str : flst_str)
        std::cout << str << " ";
    std::cout << std::endl;

    return 0;
}
