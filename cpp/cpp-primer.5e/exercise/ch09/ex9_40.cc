#include <iostream>
#include <fstream>
#include <vector>
using std::vector; using std::ifstream;
using std::string;

int main()
{
    ifstream ifs("data/words1000.txt");
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (ifs >> word)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);

    std::cout << "size: " << svec.size() << std::endl;
    std::cout << "capacity: " << svec.capacity() << std::endl;

    return 0;
}

