#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> readFile(string filename)
{
    ifstream in(filename);
    string s;
    vector<string> vstr;
    while (getline(in, s))
        vstr.push_back(s);
    in.close();
    return vstr;
}

int main()
{
    vector<string> veccontents;
    veccontents = readFile("ex_8_01.cc");

    for (int i = 0; i < veccontents.size(); i++)
        std::cout << veccontents[i] << std::endl;
    return 0;
}
