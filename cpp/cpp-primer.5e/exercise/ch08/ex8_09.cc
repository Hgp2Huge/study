#include <iostream>
#include <sstream>

using std::istream;
using std::string;
using std::istringstream;

istream& func(istream& is) {
    std::string tmp;
    while(is >> tmp)
        std::cout << tmp << std::endl;
    is.clear();
    return is;
}


int main()
{
    string line, word;
    while (getline(std::cin, line)) {
        istringstream record(line);
        func(record);
    }

    return 0;
}
