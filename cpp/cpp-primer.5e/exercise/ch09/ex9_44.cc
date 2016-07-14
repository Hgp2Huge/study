#include <iostream>
#include <string>

using std::string;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
    auto len = oldVal.size();
    for (auto pos = 0; pos <= s.size() - len; ){
        if (oldVal == s.substr(pos, len)) {
            s = s.replace(pos, len, newVal);
            pos += newVal.size();
        }
        else
            ++pos;
    }
}

int main()
{
    string s = "thotho abc thru bdn th tho oth";
    std::cout << s << std::endl;
    replace_str(s, "tho", "though");
    std::cout << s << std::endl;
    replace_str(s, "thru", "through");
    std::cout << s << std::endl;

    return 0;
}
