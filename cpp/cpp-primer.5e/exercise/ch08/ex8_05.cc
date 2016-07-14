#include <iostream>
#include <fstream>
#include <vector>

using std::vector; using std::string; using std::ifstream;

void ReadFileToVecInWord(const string& filename, vector<string>& vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
    ifs.close();
}

int main()
{
    vector<string> vec;
    ReadFileToVecInWord("ex8_01.cc", vec);

    for (const auto &str : vec)
        std::cout << str << std::endl;
    return 0;
}
