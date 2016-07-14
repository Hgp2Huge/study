#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::ifstream;

int main()
{
    ifstream ifs("data/words.txt");
    string asce_desce("gjpqybdfhiklt");
    string word, result;
    while (ifs >> word) {
        if (string::npos == word.find_first_of(asce_desce) && result.size() < word.size())
            result = word;
    }
    ifs.close();

    std::cout <<  result << std::endl;
    return 0;
}
