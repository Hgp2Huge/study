#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using std::string; using std::vector;
using std::istringstream; using std::ostringstream;
using std::ifstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(string num)
{
    /*...*/
    return true;
}

string format(string num)
{
    /*...*/
    return num;
}

int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);
    string line, word;
    vector<PersonInfo> people;

    while (getline(ifs, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    ifs.close();

    for (const auto &entry : people) {
         ostringstream formatted, bad_nums;
         for (const auto &nums : entry.phones) {
             if (!valid(nums))
                 bad_nums << " " << nums;
             else
                 formatted << " " << format(nums);
         }
         if (bad_nums.str().empty())
             std::cout << entry.name << " "
                       << formatted.str() << std::endl;
         else
             std::cerr << "input error: " << entry.name
                        << "invalid number(s) " << bad_nums.str() << std::endl;
    }

    return 0;
}
