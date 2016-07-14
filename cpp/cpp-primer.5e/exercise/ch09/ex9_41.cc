#include <iostream>
#include <string>
#include <vector>

using std::string; using std::vector;

int main()
{
    vector<char> vchar = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    string hello;
    for (const auto c : vchar)
        hello.push_back(c);
    std::cout << hello << std::endl;

    return 0;
}

