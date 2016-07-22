#include <iostream>
#include <string>

using std::string;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
    auto len = oldVal.size();
    for (auto pos = s.begin(); pos <= s.end() - len; ) {
        if (oldVal == string(pos, pos + len)) {
            pos = s.erase(pos, pos + len);
            pos = s.insert(pos, newVal.begin(), newVal.end());
            pos += newVal.size();
        }
        else
            ++pos;
    }
}


int main()
{
    string s = "thotho abctho thru bdn th tho oth";
    std::cout << s << std::endl;
    replace_str(s, "tho", "though");
    std::cout << s << std::endl;
    replace_str(s, "thru", "through");
    std::cout << s << std::endl;

    return 0;
}
