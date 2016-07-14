#include <iostream>
#include <vector>
#include <sstream>

using std::string; using std::vector;
using std::istringstream; using std::cin;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;

    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;
        record.clear(); // important
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (auto const &p : people) {
        std::cout << p.name << " ";
        for (auto const &s : p.phones)
            std::cout << s << " ";
        std::cout << std::endl;
    }

    return 0;
}
