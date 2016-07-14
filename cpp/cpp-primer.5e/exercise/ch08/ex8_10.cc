#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::ifstream; using std::istringstream;
using std::string; using std::vector;

int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);
    vector<string> vec_str;
    string line;
    while (getline(ifs, line)) {
       vec_str.push_back(line);
    }
    ifs.close();

    string word;
    for (auto const &str_line : vec_str) {
        istringstream iss_line(str_line);
        while (iss_line >> word)
           std::cout << word << std::endl;
    }
    return 0;
}
