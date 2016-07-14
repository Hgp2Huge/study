#include <iostream>
#include <string>
using std::string;

int main()
{
    string str("ab2c3d7R4E6");
    string numbers("0123456789");

    // find numbers
    auto pos = 0;
    while (string::npos != (pos = str.find_first_of(numbers, pos))) {
        std::cout << str[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;
    // find alphabet
    pos = 0;
    while (string::npos != (pos = str.find_first_not_of(numbers, pos))) {
        std::cout << str[pos] << " ";
        ++pos;
    }

    return 0;
}
