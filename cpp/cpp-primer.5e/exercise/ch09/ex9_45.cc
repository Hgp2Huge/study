#include <iostream>
#include <string>

using std::string;

string add_info(string name, const string &prefix, const string &suffix)
{
    name += " ";
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    name = name.append(suffix);
    return name;
}

int main()
{
    string name = add_info("Henry", "Mr.", "Jr.");
    std::cout << name << std::endl;
}
